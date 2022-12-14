//
// Created by alumno on 14/12/22.
//

#ifndef FORCEFIELD_GRAPH_H
#define FORCEFIELD_GRAPH_H

#include <Eigen/Dense>
#include <YoloObjects.h>
#include <QtCore>
#include <QColor>
#include <abstract_graphic_viewer/abstract_graphic_viewer.h>
#include <JointMotorSimple.h>
#include <OmniRobot.h>
#include <stdio>
#include <list>

class Graph {
private:
    struct nodo{
        int id;//nombre del vertice o nodo
    };

    struct arista{
        int from, to;
    };

    std::vector<arista> aristas;
    std::vector<nodo> nodos;

public:

};


#endif //FORCEFIELD_GRAPH_H
