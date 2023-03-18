#include"chef.h"
#include<iostream>
using namespace std;
Chef::Chef(std::string _name, std::string _signatureDish)
{
    this->name=_name;
    this->signatureDish=_signatureDish;
}
bool Chef::isSignatureDish(std::string dish)
{
    if(dish==signatureDish)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Chef::cook(std::string dish)
{
    if(isSignatureDish(dish))
    {
        std::cout<<name<<" made an awesome "<<dish<<endl;
    }
    else
    {
        std::cout<<name<<" made a plain "<<dish<<endl;
    }
}