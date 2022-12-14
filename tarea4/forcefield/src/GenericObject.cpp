//
// Created by alumno on 14/12/22.
//

#include "GenericObject.h"


GenericObject::GenericObject(const RoboCompYoloObjects::TBox &box){
    id = box.id;
    type= box.type;
    left=box.left;
    top= box.top;
    right= box.right;
    bot= box.bot;
    score= box.score;
    depth= box.depth;
    x= box.x;
    y= box.y;
    z= box.z;
}

GenericObject::GenericObject(const Door_detector::Door &door){
    id=81;
    x=door.p_center.x();
    y=door.p_center.y();
    z=0;
}

std::vector<GenericObject> GenericObject::create_list(const std::vector<Door_detector::Door> &doors){
    std::vector<GenericObject> objects;
    for(const auto d: doors)
        objects.emplace_back(GenericObject(d));
    return objects;
}

std::vector<GenericObject> GenericObject::create_list(const std::vector<RoboCompYoloObjects::TBox> &objs){
    std::vector<GenericObject> objects;
    for(const auto o: objs)
        objects.emplace_back(GenericObject(o));
    return objects;
}

Eigen::Vector2f GenericObject::TagetCoordenates(){
    return Eigen::Vector2f {x,y};
}

