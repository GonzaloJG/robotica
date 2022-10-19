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


class SpecificWorker : public GenericWorker
{
Q_OBJECT
public:
    SpecificWorker(TuplePrx tprx, bool startup_check);
    ~SpecificWorker();
    bool setParams(RoboCompCommonBehavior::ParameterList params);

    float realizarMedia(RoboCompLaserMulti::TLaserData &copy);
    tuple<float, float> fIDLE(RoboCompLaserMulti::TLaserData &ldata);
    tuple<float, float> fFORWARD(RoboCompLaserMulti::TLaserData &ldata);
    tuple<float, float> fTURN(RoboCompLaserMulti::TLaserData &ldata);
    tuple<float, float> fFOLLOW_WALL(RoboCompLaserMulti::TLaserData &ldata);
    tuple<float, float> fSPIRAL(RoboCompLaserMulti::TLaserData &ldata);


public slots:
    void compute();
    int startup_check();
    void initialize(int period);


private:
    std::shared_ptr < InnerModel > innerModel;
    bool startup_check_flag;

    enum class State {IDLE, FORWARD, TURN, FOLLOW_WALL, SPIRAL};
    State state = State::IDLE;




    struct Constants
    {
        const float MAX_ADV_SPEED = 1500;
        const float MAX_ROT_SPPED = 1.2;
        const float MAX_DIST_PARADA = 1200;
        float addvSpiral = 1;
        float rotSpiral = MAX_ROT_SPPED;
    };
    Constants consts;
};

#endif