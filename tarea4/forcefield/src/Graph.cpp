#include "Graph.h"

int Graph::add_node()
{
    Node nodo = Node(id_counter);
    nodes.insert({id_counter, nodo});
    return id_counter;
}

int Graph::add_node(int node_dest)
{
    Node nodo = Node(node_dest);
    nodes.insert({node_dest, nodo});
    add_edge(id_counter, node_dest);
    id_counter=node_dest;
    return node_dest;
}

void Graph::add_edge(int n1, int n2)
{
    Edge edge=Edge(n1, n2);
    std::pair<int, int> aux = std::make_pair(n1,n2);
    edges.insert({aux, edge});
}

void Graph::add_tags(int id, const std::vector<rc::GenericObject> &objects_yolo)
{
    for (auto &entry : nodes)
        if(entry.first==id)
            for(auto &object : objects_yolo)
                auto prueba = entry.second.objects.insert(object);
}

void Graph::draw(AbstractGraphicViewer *viewer)
{

}

void Graph::show_graph(){
    qInfo()<<"########################################################################";
    for (const auto &entry : nodes) {
        int id = entry.first;
        qInfo() << " Nodo: " << id;
        for (const auto &entryy: edges) {
            if (entryy.first.first == id) {
                qInfo() << " Enlaces: ";
                qInfo() << "Origen: " << entryy.first.first;
                qInfo() << "Destino: " << entryy.first.second;
            }
        }
    }
    qInfo()<<"########################################################################";
}