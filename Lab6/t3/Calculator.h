#pragma once
#include"PerformStrategy.h"
#include"LevelStrategy.h"
#include<iostream>
class Calculator
{
    public:
        PerformStrategy* pp;
        LevelStrategy*lp;
        Calculator(LevelStrategy*_lp,PerformStrategy* _pp)
        {
            pp=_pp;
            lp=_lp;
        }
        int get_base()
        {
            if(lp->level==1)
            {
                return 2000;
            }
            else
            {
                if(lp->level==2)
                {
                    return 5000;
                }
                else
                {
                    return 10000;
                }
            }
        }
        int get_total(int base)
        {
            if(pp->perform<0.5)
            {
                return base+1000;
            }
            else
            {
                if(pp->perform<0.8)
                {
                    return base+(pp->perform)*base;
                }
                else
                {
                    return base+2*(pp->perform)*base;
                }
            }
        }

};