#pragma once
#include<iostream>
#include"vehicle.h"
class Car:public Vehicle
{
    private:
        int mnum;
        string mname;

    public:
        Car(int num,string name):Vehicle(num,name)
        {
            mnum=num;
            mname=name;
        }
        void describe();

};
