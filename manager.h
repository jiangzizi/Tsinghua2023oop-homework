#include<string>
#include<iostream>
#include<vector>
#include"chef.h"
using namespace std;
class Manager
{
    private:
        vector <Chef> arr;
        int num;
    public:
        Manager(){num=0;}
        void newChef(Chef a);
        void order(string dish);
        void order(string dish,int chefId);

};