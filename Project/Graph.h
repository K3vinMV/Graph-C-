#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include "Store.h"


class Graph
{
    public:
        NodeVertex *hG;


        Graph();
        Graph(NodeVertex*);

        void insertVertex(class Store);
        NodeVertex* searchVertex(string);
        void insertEdge(string,string,int);
        void display();
        void removeEdge(string,string);
        int Size();
        void loadVertex();
        void loadEdge();
        void write(NodeVertex*);

};

#endif // GRAPH_H
