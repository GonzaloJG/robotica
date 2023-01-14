#include "Graph.h"
#include <cppitertools/enumerate.hpp>

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

void Graph::add_tags(int id, const std::vector<rc::GenericObject> &objects)
{
    if(nodes.contains(id))
    {
        for(const auto &o: objects)
            nodes.at(id).objects.insert(o.label);
    }
}

void Graph::draw(AbstractGraphicViewer *viewer)
{
    static std::vector<QGraphicsItem *> items;
    for(const auto &item: items)
        viewer->scene.removeItem(item);
    items.clear();

    auto width = viewer->scene.sceneRect().width();
    int tamSeparacionElipse=width/6;
    for(const auto &[i, node] : nodes | iter::enumerate)
    {
        //const auto &[key, value] = node;
        auto item = viewer->scene.addEllipse(-50, -50, 100, 100, QPen(QColor("blue"), 10));
        item->setPos(i*tamSeparacionElipse, 125);
        items.push_back(item);

        std::string result = std::to_string(node.second.objects.size());
        auto text = viewer->scene.addText(result.c_str());
        text->setPos(i*tamSeparacionElipse, 125);
        items.push_back(text);

    }
    for(const auto &[i, edges] : edges | iter::enumerate)
    {
        auto item = viewer->scene.addLine(50, 0, 116, 0, QPen(QColor("blue"), 10));
        item->setPos(i*tamSeparacionElipse, 125);
        items.push_back(item);
    }

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
