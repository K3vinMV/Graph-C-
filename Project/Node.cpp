#include "Node.h"

NodeVertex::NodeVertex()
{
    nextVer=nullptr;
    hE=nullptr;
}

NodeVertex::NodeVertex(Store data, NodeVertex *nextVer, NodeEdge *hA)
{
    this->data=data;
    this->nextVer=nextVer;
    this->hE=hE;
}

NodeEdge::NodeEdge()
{
    distance=0;
    destination=nullptr;
    nextEdge=nullptr;
}

NodeEdge::NodeEdge(int distance, NodeVertex *destination, NodeEdge *nextEdge)
{
    this->distance=distance;
    this->destination=destination;
    this->nextEdge=nextEdge;
}
