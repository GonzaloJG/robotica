#include "Graph.h"

int Graph::add_node(){
    Node nodo = Node(id_counter);
    nodes.insert({id_counter, nodo});
    return id_counter;
}

int Graph::add_node(int node_dest){
    id_counter=node_dest;
    return add_node();
}

void Graph::add_edge(int n1, int n2){
    Edge edge=Edge(n1, n2);
    std::pair<int, int> aux = std::make_pair(n1,n2);
    edges.insert({aux, edge});
}

void Graph::add_tags(int id, const std::vector<rc::GenericObject> &objects){

}

void Graph::draw(AbstractGraphicViewer *viewer){

}
