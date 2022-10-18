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
 *    along with RoboComp.  If not, see http://www.gnu.org/licenses/.
 */

/**
    \brief
    @author authorname
*/


#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#include <genericworker.h>
#include <innermodel/innermodel.h>
#include <ranges>


#define MAX_ADV_SPEED 500
#define MAX_ROT_SPPED 1.2
#define MAX_DIST_PARADA 700

class SpecificWorker : public GenericWorker
{
Q_OBJECT
public:
    SpecificWorker(TuplePrx tprx, bool startup_check);
    ~SpecificWorker();
    bool setParams(RoboCompCommonBehavior::ParameterList params);

    float realizarMedia(RoboCompLaser::TLaserData &copy);
    tuple<float, float> fIDLE(RoboCompLaser::TLaserData &ldata);
    tuple<float, float> fFORWARD(RoboCompLaser::TLaserData &ldata);
    tuple<float, float> fTURN(RoboCompLaser::TLaserData &ldata);
    tuple<float, float> fFOLLOW_WALL(RoboCompLaser::TLaserData &ldata);
    tuple<float, float> fSPIRAL(RoboCompLaser::TLaserData &ldata);


public slots:
    void compute();
    int startup_check();
    void initialize(int period);


private:
    std::shared_ptr < InnerModel > innerModel;
    bool startup_check_flag;

    enum class State {IDLE, FORWARD, TURN, FOLLOW_WALL, SPIRAL};
    State state = State::IDLE;

    float addvSpiral = 1;
    float rotSpiral = MAX_ROT_SPPED;


};

#endif