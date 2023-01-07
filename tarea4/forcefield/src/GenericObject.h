//
// Created by alumno on 14/12/22.
//

//#ifndef FORCEFIELD_GENERICOBJECT_H
//#define FORCEFIELD_GENERICOBJECT_H
//
//#include <Eigen/Dense>
//#include <YoloObjects.h>
//#include <JointMotorSimple.h>
//#include <OmniRobot.h>
//#include "door_detector.h"
//
//
//class GenericObject {
//public:
//    int id;
//    int type;
//    int left;
//    int top;
//    int right;
//    int bot;
//    float score;
//    float depth;
//    float x;
//    float y;
//    float z;
//
//    GenericObject(const RoboCompYoloObjects::TBox &box);
//    GenericObject(const Door_detector::Door &door);
//    GenericObject();
//
//    static std::vector<GenericObject> create_list(const std::vector<Door_detector::Door> &doors);
//    static std::vector<GenericObject> create_list(const std::vector<RoboCompYoloObjects::TBox> &objs);
//    Eigen::Vector2f TagetCoordenates();
//};
//
//
//#endif //FORCEFIELD_GENERICOBJECT_H


#ifndef FORCEFIELD_GENERICOBJECT_H
#define FORCEFIELD_GENERICOBJECT_H

#include <YoloObjects.h>
#include <Eigen/Dense>
#include "door_detector.h"

namespace rc
{
    class GenericObject
    {
    public:
        GenericObject() = default;
        GenericObject(const Door_detector::Door &d);
        GenericObject(const RoboCompYoloObjects::TBox &box, const  Eigen::Transform<float, 3, Eigen::Affine> &tf);
        Eigen::Vector3f get_robot_coordinates() const;
        Eigen::Vector3f get_local_coordinates() const;
        void print() const;
        static std::vector<GenericObject> add_doors(const std::vector<Door_detector::Door>     &doors);
        static std::vector<GenericObject> add_yolo(const std::vector<RoboCompYoloObjects::TBox> &boxes, const  Eigen::Transform<float, 3, Eigen::Affine> &tf);

        int id = 0;         // 0:person     80:door
        int type = -1;
        int left;
        int top;
        int right;
        int bot;
        float score;  // 0-1
        float depth;  // distance to bbox center in mm
        // local coordinates, as seen from de device where it was detected
        float x;      // roi center coordinates in camera CS
        float y;
        float z;
        // robot coordinates, as seen from the base of the robot
        float rx;
        float ry;
        float rz;

    };

} // rc

#endif //FORCEFIELD_GENERICOBJECT_H

