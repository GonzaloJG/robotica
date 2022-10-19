/*
 *    Copyright (C) 2022 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "specificworker.h"

/**
* \brief Default constructor
*/

SpecificWorker::SpecificWorker(TuplePrx tprx, bool startup_check) : GenericWorker(tprx)
{
    this->startup_check_flag = startup_check;
    // Uncomment if there's too many debug messages
    // but it removes the possibility to see the messages
    // shown in the console with qDebug()
//	QLoggingCategory::setFilterRules("*.debug=false\n");
}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker()
{
    std::cout << "Destroying SpecificWorker" << std::endl;
}


bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params)
{
    return true;
}


void SpecificWorker::initialize(int period)
{
    std::cout << "Initialize worker" << std::endl;
    this->Period = period;
    if(this->startup_check_flag)
    {
        this->startup_check();
    }
    else
    {
        timer.start(Period);
    }

}

void SpecificWorker::compute()
{
    //robot control
    RoboCompLaserMulti::TLaserData ldata;
    try
    { ldata = lasermulti_proxy->getLaserData(1);}
    catch (const Ice::Exception &e) {std::cout << e.what() << std::endl; return ;}


    std::tuple<float, float> tuplaAux;
    switch(state)
    {
        case State::IDLE:
            tuplaAux=fIDLE(ldata);
            break;

        case State::FORWARD:
            tuplaAux=fFORWARD(ldata);
            break;

        case State::TURN:
            tuplaAux=fTURN(ldata);
            break;

        case State::FOLLOW_WALL:
            tuplaAux=fFOLLOW_WALL(ldata);
            break;

        case State::SPIRAL:
            tuplaAux=fSPIRAL(ldata);
            break;
    }

    //robot actua
    qInfo()<< "addv: "<< get<0>(tuplaAux) << " rot:" << get<1>(tuplaAux);
    try
    { differentialrobotmulti_proxy->setSpeedBase(1, get<0>(tuplaAux),get<1>(tuplaAux));}
    catch (const Ice::Exception &e) {std::cout << e.what() << std::endl; }
}

///////////////////////////////////////////////////////////////////////////////////////

float SpecificWorker::realizarMedia(RoboCompLaserMulti::TLaserData &copy){
    float suma=0, media;
    for (long unsigned int i=0; i < copy.size(); i++){
        suma+=copy.at(i).dist;
    }

    media=suma/copy.size();

    return media;
}

tuple<float, float> SpecificWorker::fIDLE(RoboCompLaserMulti::TLaserData &ldata){
    const int part = 3;
    RoboCompLaserMulti::TLaserData copy(ldata.begin()+ldata.size()/part, ldata.end()-ldata.size()/part);
    std::ranges::sort(copy, {},&RoboCompLaserMulti::TData::dist);



    RoboCompLaserMulti::TLaserData copyAll(ldata.begin(), ldata.end());
    std::ranges::sort(copyAll, {},&RoboCompLaserMulti::TData::dist);

    tuple<float, float> tuplaAux = make_tuple(0,0);

    qInfo() <<"IDLE:"<< " distancia:" <<copyAll.front().dist;


    if(copy.front().dist < consts.MAX_DIST_PARADA){


        state=State::TURN;
    } else {
//        if (copyAll.front().dist > 2000){
//            state = State::SPIRAL;
//            addvSpiral = 1;
//            rotSpiral = MAX_ROT_SPPED;
//        } else {
          state=State::FORWARD;
//        }
    }

    return tuplaAux;
}


tuple<float, float> SpecificWorker::fFORWARD(RoboCompLaserMulti::TLaserData &ldata)
{
    const int part = 3;
    RoboCompLaserMulti::TLaserData copy(ldata.begin()+ldata.size()/part, ldata.end()-ldata.size()/part);
    std::ranges::sort(copy, {},&RoboCompLaserMulti::TData::dist);

    RoboCompLaserMulti::TLaserData copyAll(ldata.begin(), ldata.end());
    std::ranges::sort(copyAll, {},&RoboCompLaserMulti::TData::dist);

    qInfo() <<"FORWARD:"<< " distancia:" <<copy.front().dist;

    tuple<float, float> tuplaAux;


    if(copy.front().dist < consts.MAX_DIST_PARADA)
    {
        state=State::TURN;
        tuplaAux = make_tuple(0, 0);
    }else
//    else if (copyAll.front().dist > 2000)
//    {
//        state = State::SPIRAL;
//        consts.addvSpiral = 1;
//        consts.rotSpiral = consts.MAX_ROT_SPPED;
//        tuplaAux = make_tuple(0, 0);
//    }
//    else
        tuplaAux = make_tuple(consts.MAX_ADV_SPEED, 0);

    return tuplaAux;
}


tuple<float, float> SpecificWorker::fTURN(RoboCompLaserMulti::TLaserData &ldata)
{
    static bool primera_vez=true;
    static  bool giro_derecha=true;

    const int part = 3;
    RoboCompLaserMulti::TLaserData copy(ldata.begin()+ldata.size()/part, ldata.end()-ldata.size()/part);
    std::ranges::sort(copy, {},&RoboCompLaserMulti::TData::dist);

    RoboCompLaserMulti::TLaserData copyAll(ldata.begin()+ldata.size()/part, ldata.end()-ldata.size()/part);
    std::ranges::sort(copyAll, {},&RoboCompLaserMulti::TData::dist);

    const int partRotacion = 2;
    RoboCompLaserMulti::TLaserData copyDer(ldata.begin(), ldata.end()-ldata.size()/partRotacion);
    std::ranges::sort(copyDer, {},&RoboCompLaserMulti::TData::dist);

    RoboCompLaserMulti::TLaserData copyIzq(ldata.begin()+ldata.size()/partRotacion, ldata.end());
    std::ranges::sort(copyIzq, {},&RoboCompLaserMulti::TData::dist);

    qInfo() <<"TURN:"<< " distancia:" <<copy.front().dist;
    qInfo() <<"IDLE:"<< " mediaIzq:" <<realizarMedia(copyIzq) << " mediaDer:"<< realizarMedia(copyDer);

    tuple<float, float> tuplaAux;

    if(copy.front().dist >= consts.MAX_DIST_PARADA) {
        //Comprobar si hay una pared a su izquierda o derecha y ver a que distancia está, si esta a una cierta distancia hacer el seguir pared sino hacer el FORWARD
        state = State::FORWARD;
        //state = State::FOLLOW_WALL;
        tuplaAux = make_tuple(0, 0);
    }

    if (primera_vez)
    {
        if (realizarMedia(copyIzq) > realizarMedia(copyDer)) {
            giro_derecha = false;
            primera_vez = false;
        }
    }

    if (giro_derecha)
        tuplaAux = make_tuple(0, 0.5);
    else
        tuplaAux = make_tuple(0, -0.5);

    return tuplaAux;
}


tuple<float, float> SpecificWorker::fFOLLOW_WALL(RoboCompLaserMulti::TLaserData &ldata){
    const int part = 5;
    RoboCompLaserMulti::TLaserData copyFrente(ldata.begin()+(2*(ldata.size()/part)), ldata.end()-(2*(ldata.size()/part)));
    std::ranges::sort(copyFrente, {},&RoboCompLaserMulti::TData::dist);

    RoboCompLaserMulti::TLaserData copyIzq(ldata.begin()+(4*(ldata.size()/part)), ldata.end());
    std::ranges::sort(copyIzq, {},&RoboCompLaserMulti::TData::dist);

    qInfo() <<"FOLLOW_WALL:"<< " distancia:" <<copyFrente.front().dist;

    tuple<float, float> tuplaAux;
    float mediaIzq = realizarMedia(copyIzq);

    qInfo() <<"FOLLOW_WALL:"<< " mediaIzq:" <<mediaIzq;

        if (mediaIzq > 1300){
            tuplaAux=make_tuple(100, -0.2);
        }else {
            if (mediaIzq < 1100){
                tuplaAux=make_tuple(100, +0.2);
            } else{
                state=State::FORWARD;
                tuplaAux= make_tuple(500,0);
            }
        }

//    if(copy.front().dist < MAX_DIST_PARADA)
//    {
//        state=State::TURN;
//        tuplaAux = make_tuple(0, 0);
//    }

    return tuplaAux;
}


tuple<float, float> SpecificWorker::fSPIRAL(RoboCompLaserMulti::TLaserData &ldata){
    const int part = 3;
    RoboCompLaserMulti::TLaserData copy(ldata.begin()+ldata.size()/part, ldata.end()-ldata.size()/part);
    std::ranges::sort(copy, {},&RoboCompLaserMulti::TData::dist);

    qInfo() <<"SPIRAL:"<< " distancia:" <<copy.front().dist;

    tuple<float, float> tuplaAux = make_tuple(consts.addvSpiral, consts.rotSpiral);

    if(consts.addvSpiral < consts.MAX_ADV_SPEED && consts.rotSpiral > 0){
        sleep(1);
        consts.addvSpiral+=50;
        consts.rotSpiral-=0.03;
    }

    if(copy.front().dist < consts.MAX_DIST_PARADA){
        state = State::TURN;
        tuplaAux = make_tuple(0, 0);
    }

    return tuplaAux;
}


int SpecificWorker::startup_check()
{
    std::cout << "Startup check" << std::endl;
    QTimer::singleShot(200, qApp, SLOT(quit()));
    return 0;
}


/**************************************/
// From the RoboCompDifferentialRobot you can call this methods:
// this->differentialrobot_proxy->correctOdometer(...)
// this->differentialrobot_proxy->getBasePose(...)
// this->differentialrobot_proxy->getBaseState(...)
// this->differentialrobot_proxy->resetOdometer(...)
// this->differentialrobot_proxy->setOdometer(...)
// this->differentialrobot_proxy->setOdometerPose(...)
// this->differentialrobot_proxy->setSpeedBase(...)
// this->differentialrobot_proxy->stopBase(...)

/**************************************/
// From the RoboCompDifferentialRobot you can use this types:
// RoboCompDifferentialRobot::TMechParams

/**************************************/
// From the RoboCompLaser you can call this methods:
// this->laser_proxy->getLaserAndBStateData(...)
// this->laser_proxy->getLaserConfData(...)
// this->laser_proxy->getLaserData(...)

/**************************************/
// From the RoboCompLaser you can use this types:
// RoboCompLaser::LaserConfData
// RoboCompLaser::TData
