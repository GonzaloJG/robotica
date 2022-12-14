//
// Created by alumno on 14/12/22.
//

#ifndef FORCEFIELD_GENERICOBJECT_H
#define FORCEFIELD_GENERICOBJECT_H

#include <Eigen/Dense>
#include <YoloObjects.h>
#include <JointMotorSimple.h>
#include <OmniRobot.h>
#include "door_detector.h"


class GenericObject {
private:
    int id;
    int type;
    int left;
    int top;
    int right;
    int bot;
    float score;
    float depth;
    float x;
    float y;
    float z;

public:
    GenericObject(const Door_detector::Door &door);
    GenericObject(const RoboCompYoloObjects::TBox &box);
    GenericObject();

    static std::vector<GenericObject> create_list(const std::vector<Door_detector::Door> &doors);
    static std::vector<GenericObject> create_list(const std::vector<RoboCompYoloObjects::TBox> &objs);
    Eigen::Vector2f TagetCoordenates();
};


#endif //FORCEFIELD_GENERICOBJECT_H
