//
// Created by alumno on 20/12/22.
//

#include "StateMachine.h"

///////////////////  State machine ////////////////////////////////////////////
void StateMachine::state_machine(const std::vector<GenericObject> genericObjects, const std::vector<Eigen::Vector2f> &line, rc::Robot &robot){
    switch(state)
    {
        case State::SEARCHING:
            search_state(genericObjects, robot);
            break;
        case State::APPROACHING:
            approach_state(genericObjects, line, robot);
            break;
        case State::WAITING:
            wait_state();
            break;
    }

}


void StateMachine::search_state(const RoboCompYoloObjects::TObjects &objects,  rc::Robot &robot){
    //Comprueba que el objeto que identifica es distinto del objeto que tenemos actualmente.
    //Una vez comprobado, si es distinto, cambia en el iterador a los atributos del nuevo objeto y cambia de estado.
    qInfo()<< __FUNCTION__<<"Buscando Target, target anterior:" << robot.get_current_target().type;
    if(auto it = std::ranges::find_if_not(objects,
                                          [r=robot](auto &a){return a.type == r.get_current_target().type;}); it != objects.end())
    {
        robot.set_current_target(*it);
        qInfo()<< __FUNCTION__<<"Target:"<<robot.get_current_target().type;
//        robot.set_pure_rotation(0.f);
        state=State::APPROACHING;

    }
        //Si no, sigue rotando.
    else
        robot.set_pure_rotation(0.5);

}
void StateMachine::approach_state(const RoboCompYoloObjects::TObjects &objects, const std::vector<Eigen::Vector2f> &line, rc::Robot &robot){
    robot.set_pure_rotation(0.f);

    if (robot.get_distance_to_target() < 800) {
        state = State::WAITING;
    }else
    if(auto it=std::find_if(objects.begin(), objects.end(),
                            [r=robot](auto &a){return a.type == r.get_current_target().type;}); it != objects.end())
        //En una funcion lamda lo que hay entre corchete es para capturar un objeto del entorno, y en a esta los elementos del it
    {
        robot.set_current_target(*it);
        qInfo()<< __FUNCTION__<<"Target:"<<robot.get_current_target().type;
    }

}

void StateMachine::wait_state(){
    static std::chrono::time_point<std::chrono::system_clock> start;
    static bool primera_vez=true;
    if (primera_vez)
    {
        start = std::chrono::system_clock::now();
        primera_vez=false;
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float,std::milli> duration = end - start;
    if(duration.count() > 2000)
    {
        state = State::SEARCHING;
        primera_vez=true;
    }
}
