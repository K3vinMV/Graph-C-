#include <iostream>
#include "Store.h"
#include "Graph.h"

using namespace std;

void pause();

int main()
{
    Graph *g=new Graph();

    Store data;
    int opt;
    string nam,cat,ori,des;

    do
    {
        system("cls");
        cout<<"------------Graph------------"<<endl;
        cout<<"1.-Insert Vertex"<<endl;
        cout<<"2.-Display Vertex"<<endl;
        cout<<"3.-Insert Edge"<<endl;
        cout<<"4.-Display"<<endl;
        cout<<"5.-Remove Edge"<<endl;
        cout<<"6.-Size"<<endl;
        cout<<"7.-Load"<<endl;
        cout<<"8.-Write"<<endl;
        cout<<"9.-Exit"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"Please enter an option: ";
        cin>>opt;

        switch(opt)
        {
        case 1:
            system("cls");
            cout<<"--------INSERT VERTEX--------"<<endl;
            int num;
            cout<<"Insert name of the store: ";
            cin.ignore();
            getline(cin, nam);
            cout<<"Insert category: ";
            getline(cin, cat);
            cout<<"Insert phone number: ";
            cin>>num;
            data.setname(nam);
            data.setcategory(cat);
            data.setnumber(num);
            g->insertVertex(data);
            pause();
            break;

        case 2:
            system("cls");
            cout<<"--------DISPLAY VERTEX--------"<<endl;
            NodeVertex *aux;
            cout<<"Insert the name of the vertex you want to search for:";
            cin.ignore();
            getline(cin, nam);
            aux=g->searchVertex(nam);
            if(aux)
            {
                cout<<"Name: "<<aux->data.getname()<<endl;
                cout<<"Category: "<<aux->data.getcategory()<<endl;
                cout<<"Phone number: "<<aux->data.getnumber()<<endl;
            }else
            {
                cout<<"Store not found..."<<endl;
            }
            pause();
            break;

        case 3:
            system("cls");
            int dist;
            cout<<"--------INSERT EDGE--------"<<endl;
            cout<<"Insert the origin store name: ";
            cin.ignore();
            getline(cin, ori);
            cout<<"Insert the destination store name: ";
            getline(cin, des);
            cout<<"Insert the distance between the stores: ";
            cin>>dist;
            g->insertEdge(ori,des,dist);
            pause();
            break;

        case 4:
            system("cls");
            cout<<"--------DISPLAY--------"<<endl;
            g->display();
            pause();
            break;

        case 5:
            system("cls");
            cout<<"--------REMOVE EDGE--------"<<endl;
            cout<<"Insert the origin store name: ";
            cin.ignore();
            getline(cin, ori);
            cout<<"Insert the destination store name: ";
            getline(cin, des);
            g->removeEdge(ori,des);
            cout<<"Edge removed successfully"<<endl;
            pause();
            break;

        case 6:
            system("cls");
            cout<<"--------SIZE--------"<<endl;
            int sz;
            sz=g->Size();
            cout<<"The total number of vertices is: "<<sz<<endl;
            pause();
            break;

        case 7:
            system("cls");
            cout<<"--------LOAD--------"<<endl;
            g->loadVertex();
            g->loadEdge();
            cout<<"Data loaded"<<endl;
            pause();
            break;

        case 8:
            system("cls");
            cout<<"--------WRITE--------"<<endl;
            g->write(g->hG);
            cout<<"Data saved successfully"<<endl;
            pause();
            break;

        case 9:
            system("cls");
            cout<<"Quitting..."<<endl;
            break;

        default:
            system("cls");
            cout<<"Not a valid option"<<endl;
            pause();
            break;
        }
    }while(opt!=9);

    return 0;
}

void pause()
{
    cout<<"Press any key to continue..."<<endl;
    getwchar();
    getwchar();
}


