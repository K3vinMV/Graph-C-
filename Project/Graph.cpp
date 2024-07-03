#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

Graph::Graph()
{
    hG=nullptr;
    //ctor
}
Graph::Graph(NodeVertex *h)
{
    hG=h;
}

NodeVertex* Graph::searchVertex(string name)
{
    NodeVertex *aux=hG;
    bool band=true;
    if(!hG)
    {
        return nullptr;
    }else
    {
        while(aux && band)
        {
            if(aux->data.getname()== name)
            {
                band=false;
            }else
            {
                aux=aux->nextVer;
            }
        }
    }
    return aux;
}

void Graph::insertVertex(class Store data)
{
    NodeVertex *tmp=new NodeVertex(data,nullptr,nullptr);
    NodeVertex *aux=hG;
    if(!hG)
    {
        hG=tmp;
    }else
    {
        while(aux->nextVer)
        {
            aux=aux->nextVer;
        }
        aux->nextVer=tmp;
    }
}

void Graph::insertEdge(string origin,string destination,int distance)
{
    NodeVertex *_origin=searchVertex(origin);
    NodeVertex *_destination=searchVertex(destination);

    if(_origin && _destination)
    {
        NodeEdge *aux=_origin->hE;
        NodeEdge *tmp=new NodeEdge(distance,_destination,nullptr);
        if(aux)
        {
            tmp->nextEdge=_origin->hE;
            _origin->hE=tmp;
        }else
        {
            _origin->hE=tmp;
        }
    }
}

void Graph::display()
{
    NodeVertex *auxVer=hG;
    NodeEdge *auxEdge=nullptr;

    while(auxVer)
    {
        cout<<auxVer->data.getname()<<": ";
        auxEdge=auxVer->hE;
        while(auxEdge)
        {
            cout<<"("<<auxEdge->destination->data.getname()<<","<<auxEdge->distance<<"m.)";
            auxEdge=auxEdge->nextEdge;
        }
        cout<<endl;
        auxVer=auxVer->nextVer;
    }
}

void Graph::removeEdge(string origin, string destination)
{
    NodeVertex* nodeOrigin=searchVertex(origin);
    if(!nodeOrigin)
    {
        cout<<"Origin vertex does not exist"<<endl;
    }else
    {
        NodeEdge* currentEdge = nodeOrigin->hE;
        NodeEdge* previousEdge = nullptr;
        while(currentEdge)
        {
            if(currentEdge->destination->data.getname()==destination)
            {
                if(previousEdge)
                {
                    previousEdge->nextEdge = currentEdge->nextEdge;
                }else
                {
                    nodeOrigin->hE = currentEdge->nextEdge;
                }
                delete currentEdge;
                return;
            }
            previousEdge = currentEdge;
            currentEdge = currentEdge->nextEdge;
        }
        cout<<"Theres no edge between "<<origin<<" and "<<destination<<endl;
    }
}

int Graph::Size()
{
    NodeVertex *aux=hG;
    int siz=0;

    while(aux)
    {
        aux=aux->nextVer;
        siz++;
    }
    return siz;
}

void Graph::loadVertex() {
    ifstream fileVertices("Vertices.txt", ios::in);

    if (!fileVertices.is_open()) {
        cerr << "File can not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    string recordVertex;

    while (getline(fileVertices, recordVertex, '*'))
    {
        stringstream ss_reg(recordVertex);
        Store aux;

        string field;

        getline(ss_reg, field, '|');
        aux.setname(field);

        getline(ss_reg, field, '|');
        aux.setcategory(field);

        getline(ss_reg, field, '|');
        aux.setnumber(stoi(field));

        insertVertex(aux);
    }

    fileVertices.close();
}

void Graph::loadEdge() {
    ifstream fileEdges("edges.txt", ios::in);

    if (!fileEdges.is_open()) {
        cerr << "File can not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    string recordEdges;

    while (getline(fileEdges, recordEdges, '*')) {
        stringstream ss_reg(recordEdges);

        string origin, destination;
        int distance;

        getline(ss_reg, origin, '|');
        getline(ss_reg, destination, '|');
        ss_reg >> distance;

        insertEdge(origin, destination, distance);
    }

    fileEdges.close();
}


void Graph::write(NodeVertex* current) {
    ofstream fileVertices("vertices.txt", ios::out);
    ofstream fileEdges("edges.txt", ios::out);

    if(!fileVertices.is_open() || !fileEdges.is_open())
    {
        cerr << "Files can not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    while(current)
    {
        fileVertices << current->data.getname() << "|" << current->data.getcategory() << "|" << current->data.getnumber() << "*";
        NodeEdge* edge = current->hE;
        while(edge)
        {
            fileEdges << current->data.getname() << "|" << edge->destination->data.getname() << "|" << edge->distance << "*";
            edge = edge->nextEdge;
        }
        current = current->nextVer;
    }
    fileVertices.close();
    fileEdges.close();
}

