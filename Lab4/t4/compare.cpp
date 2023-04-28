#include "compare.h"

class Compare1 : public AbstractCompare<int>
{
    bool compare(int a, int b)
    {
        return a > b;
    }
};

class Compare2 : public AbstractCompare<int>
{
    bool compare(int a, int b)
    {
        int x = a;
        int y = b;
        int sum1 = 0;
        int sum2 = 0;
        while (a > 0)
        {
            sum1 += a % 10;
            a = a / 10;
        }
        while (b > 0)
        {
            sum2 += b % 10;
            b = b / 10;
        }
        if (sum1 != sum2)
        {
            return sum1 > sum2;
        }
        else
        {
            return x > y;
        }
    }
};

class Compare3 : public AbstractCompare<Point>
{
    bool compare(Point a, Point b)
    {
        if (a.x != b.x)
        {
            return a.x > b.x;
        }
        else
        {
            return a.y > b.y;
        }
    }
};
class Compare4 : public AbstractCompare<Point>
{
    bool compare(Point a, Point b)
    {
        if ((a.x * a.x + a.y * a.y) != (b.x * b.x + b.y * b.y))
        {
            return ((a.x * a.x + a.y * a.y) > (b.x * b.x + b.y * b.y));
        }
        else
        {
            if (a.x != b.x)
            {
                return a.x > b.x;
            }
            else
            {
                return a.y > b.y;
            }
        }
    }
};

AbstractCompare<int> *get_compare_int(int type)
{
    if (type == 1)
    {
        AbstractCompare<int> *p = new Compare1;
        return p;
    }
    else
    {
        AbstractCompare<int> *p = new Compare2;
        return p;
    }
}
AbstractCompare<Point> *get_compare_point(int type)
{
    if (type == 3)
    {
        AbstractCompare<Point> *p = new Compare3;
        return p;
    }
    else
    {
        AbstractCompare<Point> *p = new Compare4;
        return p;
    }
}