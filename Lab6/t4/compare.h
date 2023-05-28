#pragma once
#include <functional>
#include <vector>
#include<iostream>
/*template <typename T>
class Compare
{
    public:



};*/
template <typename T>
class Compare
{
public:
    int funtype;
    std::vector<std::function<bool(T a, T b)> > funlist;
    std::function<bool(T a, T b)> fun1, fun2, fun3;
    Compare(std::vector<std::function<bool(T a, T b)> > _funlist)
    {
        funtype = 2;
        funlist = _funlist;
        //std::cout<<funlist.size()<<"!!!"<<std::endl;
    }
    bool operator()(T a, T b)
    {
        if (funtype == 1)
        {
            if (fun1(a, b) == 1)
            {
                return 1;
            }
            else
            {
                if (fun1(b, a) == 1)
                {
                    return 0;
                }
                else
                {
                    if (fun2(a, b) == 1)
                    {
                        return 1;
                    }
                    else
                    {
                        if (fun2(b, a) == 1)
                        {
                            return 0;
                        }
                        else
                        {
                            if (fun3(a, b) == 1)
                            {
                                return 1;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            
            for (int i = 0; i < funlist.size(); i++)
            {
                //std::cout<<i;
                if (funlist[i](a, b) == 1)
                {
                    return 1;
                }
                if (funlist[i](b, a) == 1)
                {
                    return 0;
                }
            }
            //return 1;
        }
    }
    Compare(std::function<bool(T a, T b)> _fun1, std::function<bool(T a, T b)> _fun2, std::function<bool(T a, T b)> _fun3)
    {
        funtype = 1;
        fun1 = _fun1;
        fun2 = _fun2;
        fun3 = _fun3;
    }
};