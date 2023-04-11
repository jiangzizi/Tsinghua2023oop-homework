#pragma once
#include<iostream>
#include"vehicle.h"
class Motor:public Vehicle
{
    private:
        int mnum;
        string mname;

    public:
        Motor(int num,string name):Vehicle(num,name)
        {
            mnum=num;
            mname=name;
        }
        void sell()
        {
            cout<<"A motor is sold!"<<endl;
        }
        void describe();

};
