//
// Created by alumno on 20/12/22.
//

#include "StateMachine.h"

///////////////////  State machine ////////////////////////////////////////////
void StateMachine::state_machine(const std::vector<rc::GenericObject> genericObjects, rc::Robot &robot, Graph &graph, AbstractGraphicViewer *viewer)
{
    switch(state)
    {
        case State::IDLE:
            idle_state(graph);
            break;
        case State::SEARCHING:
            search_state(genericObjects, robot, graph);
            break;
        case State::APPROACHING:
            approach_state(genericObjects, robot);
            break;
        case State::CROSS:
            cross_state(robot, graph, viewer);
            break;
    }

}

void StateMachine::idle_state(Graph &graph)
{
    id_nodo_actual = graph.add_node();
    state = State::SEARCHING;
}

void StateMachine::search_state(const std::vector<rc::GenericObject> genericObjects, rc::Robot &robot, Graph &graph)
{
    //Comprueba que el objeto que identifica es distinto del objeto que tenemos actualmente.
    //Una vez comprobado, si es distinto, cambia en el iterador a los atributos del nuevo objeto y cambia de estado.
    qInfo()<< __FUNCTION__<<" -> Buscando Target, target anterior:" << robot.get_current_target().type;

    graph.add_tags(id_nodo_actual, genericObjects);

    if (auto it = std::ranges::find_if_not(genericObjects.begin(), genericObjects.end(),
                                          [r=robot](auto &a){return a.type == r.get_current_target().type;}); it != genericObjects.end() && it->type == 80)
    {
            robot.set_current_target(*it);
            qInfo() << __FUNCTION__ << " -> Target encontrado: " << robot.get_current_target().type;
            state = State::APPROACHING;
    }
        //Si no, sigue rotando.
    else
    {
        qInfo() << __FUNCTION__ << " -> Rotar para buscar Target";
        robot.set_pure_rotation(0.5);
    }
    
}

void StateMachine::approach_state(const std::vector<rc::GenericObject> genericObjects, rc::Robot &robot)
{
    robot.set_pure_rotation(0.f);

    if (robot.get_distance_to_target() < 500)
    {
        qInfo()<< __FUNCTION__<<" -> Pasamos al estado CROSS!! ";
        state = State::CROSS;
    }
    else
    if (auto it=std::find_if(genericObjects.begin(), genericObjects.end(),
                            [r=robot](auto &a){return a.type == r.get_current_target().type;}); it != genericObjects.end())
        //En una funcion lamda lo que hay entre corchete es para capturar un objeto del entorno, y en a esta los elementos del it
    {
        robot.set_current_target(*it);
        qInfo()<< __FUNCTION__<<" -> Siguendo el Target: "<<robot.get_current_target().type;
    }

}


void StateMachine::cross_state(rc::Robot &robot, Graph &graph, AbstractGraphicViewer *viewer)
{
    static std::chrono::time_point<std::chrono::system_clock> start;
    static bool primera_vez=true;
    if (primera_vez)
    {
        start = std::chrono::system_clock::now();
        primera_vez=false;
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float,std::milli> duration = end - start;

    if(duration.count() > 1500)
    {
        qInfo()<< __FUNCTION__<<" -> Ha pasado a la siguiente habitacion!!";

        id_nodo_actual = graph.add_node(id_nodo_actual + 1);
        //graph.show_graph();
        graph.draw(viewer);

        robot.resetTarget();
        state = State::SEARCHING;
        primera_vez=true;
    }
}

