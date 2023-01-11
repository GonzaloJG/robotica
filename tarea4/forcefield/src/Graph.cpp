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

void Graph::add_tags(int id, const std::vector<rc::GenericObject> &objectss)
{
    for (int i=0; i<objectss.size(); i++)
        nodes.at(id).objects.insert(objectss.begin(), objectss.end());
    
}

void Graph::draw(AbstractGraphicViewer *viewer)
{

}
