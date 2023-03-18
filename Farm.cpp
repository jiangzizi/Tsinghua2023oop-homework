#include"Farm.h"
#include<iostream>
using namespace std;


Farm::Farm(int n)
{
    num=n;
    for(int i=0;i<num;i++)
    {
        test.push_back(0);
        cao.push_back(0);
    }
}
void Farm::addCow(Cow a)
{
    arr.push_back(a);
}
void Farm::supply(string name,int a)
{
    for(int i=0;i<num;i++)
    {
        if(arr[i].name==name)
        {
            cao[i]+=a;
        }
    }
}
void Farm::startMeal()
{
    for(int i=0;i<num;i++)
    {
        if(cao[i]>=arr[i].u)
        {
            test[i]=2;
            cao[i]-=arr[i].u;
        }
        else
        {
            if(cao[i]>=arr[i].l)
            {
                test[i]=2;
                cao[i]=0;
            }
            else
            {
                if(cao[i]>0)
                {
                    test[i]=1;
                    cao[i]=0;
                }
                else
                {
                    test[i]=0;
                    cao[i]=0;
                }
                
            }
            
        }
    }
}
void Farm::produceMilk()
{
    for(int i=0;i<num;i++)
    {
        if(test[i]==2)
        {
            total+=arr[i].m;
        }
        if(test[i]==1)
        {
            total+=arr[i].m*0.5;
        }
        
    }
}
double Farm::getMilkProduction()
{
    return total;
}