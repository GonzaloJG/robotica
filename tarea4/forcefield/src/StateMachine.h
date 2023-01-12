//
// Created by alumno on 20/12/22.
//

#ifndef FORCEFIELD_STATEMACHINE_H
#define FORCEFIELD_STATEMACHINE_H

#include <Eigen/Dense>
#include "robot.h"
#include "GenericObject.h"
#include "Graph.h"

class StateMachine {
public:
    // state machine
    void state_machine(const std::vector<rc::GenericObject> genericObjects, rc::Robot &robot, Graph &graph, AbstractGraphicViewer *viewer);
    enum class State {IDLE, SEARCHING, APPROACHING, CROSS};
    State state = State::IDLE;

    void search_state(const std::vector<rc::GenericObject> genericObjects, rc::Robot &robot);
    void approach_state(const std::vector<rc::GenericObject> genericObjects, rc::Robot &robot);
    void cross_state(rc::Robot &robot, Graph &graph, AbstractGraphicViewer *viewer);
    void idle_state(Graph &graph);

    int id_nodo_actual=0;
};


#endif //FORCEFIELD_STATEMACHINE_H
