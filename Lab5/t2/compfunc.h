#pragma once

#include "func.h"

class CompFunc : public Func{
private:
    // Todo
    Func *in,*out;
    // 声明成员变量
public:
    CompFunc(Func *outer, Func* inner);
    // compute f(g(x))
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个复合函数类
    // 并且要求，传入的参数的析构在该类被析构时同时析构
    double getPoint(double point)
    {
        return out->getPoint(in->getPoint(point));
    }
    ~CompFunc(){
        delete in;
        delete out;
    }
};
CompFunc::CompFunc(Func *outer,Func* inner)
{
    in=std::move(inner);
    out=std::move(outer);
    //delete outer;
    //delete inner;
}