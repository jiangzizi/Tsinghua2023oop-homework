#pragma once

#include "func.h"

class LinearFunc : public Func{
private:
    double ia,ib;
    
public:
    LinearFunc(double a, double b);
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个一次函数类
    // f(x) = ax + b;
    double getPoint(double point)
    {
        return ia*point+ib;
    }
};
LinearFunc::LinearFunc(double a,double b)
{
    this->ia=a;
    this->ib=b;
}
