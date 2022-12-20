//
// Created by alumno on 20/12/22.
//

#ifndef FORCEFIELD_STATEMACHINE_H
#define FORCEFIELD_STATEMACHINE_H

#include <Eigen/Dense>
#include "robot.h"
#include "GenericObject.h"

class StateMachine {
public:
    // state machine
    void state_machine(const std::vector<GenericObject> genericObjects, const std::vector<Eigen::Vector2f> &line, rc::Robot &robot);
    enum class State {IDLE, SEARCHING, APPROACHING, WAITING};
    State state = State::SEARCHING;
    void search_state(const std::vector<GenericObject> genericObjects,  rc::Robot &robot);
    void approach_state(const std::vector<GenericObject> genericObjects, const std::vector<Eigen::Vector2f> &line,  rc::Robot &robot);
    void wait_state();
};


#endif //FORCEFIELD_STATEMACHINE_H
