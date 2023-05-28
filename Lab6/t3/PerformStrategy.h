#pragma once;
#include<iostream>
class PerformStrategy
{
    public:
    virtual ~PerformStrategy(){};
    int type;
    double perform;
};
class sPerformStrategy :public PerformStrategy
{
    public:
        sPerformStrategy(double _perform)
        {
            type=1;
            
            perform=_perform;
            //std::cout<<perform;
        }



};
class mPerformStrategy:public PerformStrategy
{
    public:
        mPerformStrategy(double _perform)
        {
            type=2;
            
            perform=_perform;
        }


};
class lPerformStrategy:public PerformStrategy
{
    public:
        lPerformStrategy(double _perform)
        {
            type=1;
            
            perform=_perform;
        }

};