#ifndef STORE_H
#define STORE_H
#include <iostream>

using namespace std;

class Store
{
    public:
        void setname(string nam)
        {
            name=nam;
        }
        string getname()
        {
            return name;
        }
        void setnumber(int num)
        {
            number=num;
        }
        int getnumber()
        {
            return number;
        }
        void setcategory(string cat)
        {
            category=cat;
        }
        string getcategory()
        {
            return category;
        }
        Store();

    private:
        string name;
        int number;
        string category;
};

#endif // STORE_H
