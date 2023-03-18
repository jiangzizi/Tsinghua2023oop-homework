#include"manager.h"
#include<iostream>
using namespace std;
void Manager::newChef(Chef a)
{
    num++;
    arr.push_back(a);
}
void Manager::order(string dish)
{
    bool t=0;
    for(int i=0;i<num;i++)
    {
        if(arr[i].isSignatureDish(dish))
        {
            t=1;
            arr[i].cook(dish);
            break;

        }
    }
    if(t==0)
    {
        arr[0].cook(dish);
    }
}
void Manager::order(string dish,int chefId)
{
    arr[chefId].cook(dish);
}