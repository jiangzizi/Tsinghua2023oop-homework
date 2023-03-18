#pragma once
#include<iostream>
#include<vector>
#include"Cow.h"
using namespace std;
class Farm
{
    private:
        int num;
        vector<Cow> arr;
        double total=0.0;
        vector<int> test;
        vector<int> cao;
    public:
        Farm(int n);
        void addCow(Cow a);
        void supply(string name,int a);
        void startMeal();
        void produceMilk();
        double getMilkProduction();

};