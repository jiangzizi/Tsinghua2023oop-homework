#pragma once;
#include <iostream>
class LevelStrategy
{
public:
    virtual ~LevelStrategy(){};
    int level;
};
class P1LStrategy : public LevelStrategy
{
public:
    P1LStrategy()
    {
        level = 1;
        //std::cout << 1;
    }
    ~P1LStrategy() {}
};
class P2LStrategy : public LevelStrategy
{
public:
    P2LStrategy()
    {
        //std::cout << 2;
        level = 2;
    }
    ~P2LStrategy() {}
};
class P3LStrategy : public LevelStrategy
{
public:
    P3LStrategy()
    {
        //std::cout << 3;
        level = 3;
    }
    ~P3LStrategy() {}
};