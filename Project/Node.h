#ifndef NODE_H
#define NODE_H
#include "Store.h"

class NodeEdge;

class NodeVertex
{
    public:
        Store data;
        NodeVertex *nextVer;
        NodeEdge *hE;

        NodeVertex();
        NodeVertex(Store,NodeVertex*,NodeEdge*);
};

class NodeEdge
{
    public:
        int distance;
        NodeVertex *destination;
        NodeEdge *nextEdge;

        NodeEdge();
        NodeEdge(int,NodeVertex*,NodeEdge*);

};

#endif // NODE_H
