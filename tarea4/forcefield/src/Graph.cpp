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

void Graph::add_tags(int id, const std::vector<rc::GenericObject> &objects_yolo)
{
//    for (const auto &[key, value]  : nodes)
//        if (key == id)
}

//void Graph::draw(AbstractGraphicViewer *viewer)
//{
//    static std::vector<QGraphicsItem *> items;
//    for(const auto &item: items)
//        viewer->scene.removeItem(item);
//    items.clear();
//
//    auto width = viewer->scene.sceneRect().width();
//    int tamSeparacionElipse=width/6;
//    for(const auto &[i, node] : nodes | iter::enumerate)
//    {
//        //const auto &[key, value] = node;
//        auto item = viewer->scene.addEllipse(-50, -50, 100, 100, QPen(QColor("blue"), 10));
//        item->setPos(i*tamSeparacionElipse, 125);
//        items.push_back(item);
//
////        std::string result = std::to_string(node.second.objects.size());
////        auto text = viewer->scene.addText(result.c_str());
////        text->setPos(i*tamSeparacionElipse, 125);
////        items.push_back(text);
//
//    }
//    for(const auto &[i, edges] : edges | iter::enumerate)
//    {
//        auto item = viewer->scene.addLine(50, 0, 116, 0, QPen(QColor("blue"), 10));
//        item->setPos(i*tamSeparacionElipse, 125);
//        items.push_back(item);
//    }
//
//}

void Graph::draw(AbstractGraphicViewer *viewer)
{
    if(viewer == nullptr) return;
    static std::vector<QGraphicsItem *> items;
    for (auto i: items)
    {
        viewer->scene.removeItem(i);
        delete i;
    }
    items.clear();

    const int max_cols = 6;
    //int rows_step = viewer->height() / 4;
    qInfo() << __FUNCTION__ << viewer->scene.sceneRect().width() << viewer->scene.sceneRect().height();
    int rows_step = viewer->scene.sceneRect().height() / 2;
    int cols_step = viewer->scene.sceneRect().width() / (2 * max_cols);
    int rows = rows_step, cols = cols_step;
    //nodes
    for (auto &&[i, node]: nodes | iter::enumerate)
    {
        qInfo() << __FUNCTION__ << rows << cols;
//        if ((i + 1) % (max_cols + 1) == 0)
//        {
//            rows = rows + 2 * rows_step;
//            cols = cols_step;
//        } else
        auto &[k, v] = node;
        v.draw_pos.setX(cols);
        v.draw_pos.setY(rows);
        auto item = viewer->scene.addEllipse(-100, -100, 200, 200, QPen(QColor("brown"), 20));
        item->setPos(v.draw_pos);
        items.push_back(item);
        cols = cols + 2*cols_step;

        auto item_t = viewer->scene.addSimpleText(QString::number(v.objects.size()), QFont("times", 30));
        item_t->setPos(v.draw_pos);
        items.push_back(item_t);
    }
    //edges
    for (auto &&[i, edge]: edges | iter::enumerate)
    {
        auto &[k, v] = edge;
        auto &[n1, n2] = k;
        auto p1 = nodes.at(n1).draw_pos;
        auto p2 = nodes.at(n2).draw_pos;
        auto minx = std::min(p1.x(), p2.x());
        auto maxx = std::max(p1.x(), p2.x());
        auto item = viewer->scene.addLine(minx+100, p1.y(), maxx-100, p2.y(), QPen(QColor("brown"), 10));
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
                qInfo() << "Nodo1: " << entryy.first.first;
                qInfo() << "Nodo2: " << entryy.first.second;
            }
        }
    }
    qInfo()<<"########################################################################";
}
