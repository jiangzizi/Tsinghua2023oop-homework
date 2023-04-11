#pragma once
#include <iostream>
#include "engine.h"
#include "wheel.h"
using namespace std;
class Vehicle
{
private:
public:
    Engine e;
    string ename;
    int wnum;
    Wheel w;
    Vehicle(int num, string name) : w(num), e(name)
    {
        ename = name;
        wnum = num;
    }
    Vehicle();
    void describe();
};