#include "Rack.h"
ostream &operator<<(ostream &out, const Rack &tmp)
{
    // out<<tmp.num;
    for (int i = 0; i < tmp.num; i++)
    {
        out << " " << tmp.arr[i];
    }
    return out;
}
int operator<(const Rack &a, const Rack &b)
{
    if (a.num < b.num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int operator>(const Rack &a, const Rack &b)
{

    if (a.num > b.num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int operator==(const Rack &a, const Rack &b)
{
    if (a.num == b.num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
Rack operator,(const Rack &a, const Rack &b)
{
    Rack tmp(a.num + b.num);
    for (int i = 0; i < a.num; i++)
    {
        tmp.arr.push_back(a.arr[i]);
    }
    for (int i = a.num; i < tmp.num; i++)
    {
        tmp.arr.push_back(b.arr[i - a.num]);
    }
    return tmp;
}
Rack operator,(int a, const Rack &b)
{
    Rack tmp(1 + b.num);
    tmp.arr.push_back(a);
    for (int i = 0; i < b.num; i++)
    {
        tmp.arr.push_back(b.arr[i]);
    }
    return tmp;
}
Rack operator,(const Rack &a, int b)
{
    Rack tmp(a.num + 1);
    for (int i = 0; i < a.num; i++)
    {
        tmp.arr.push_back(a.arr[i]);
    }
    tmp.arr.push_back(b);
    return tmp;
}
Rack operator&(const Rack &a, const Rack &b)
{
    Rack tmp;
    vector<int> k;
    int p = -1;
    for (int i = 0; i < a.num; i++)
    {
        for (int j = 0; j < b.num; j++)
        {
            if (a.arr[i] == b.arr[j])
            {
                bool flag = 1;
                for (int h = 0;  h < tmp.num; h++)
                {
                    if (a.arr[i] == tmp.arr[h])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    tmp.num++;
                    tmp.arr.push_back(a.arr[i]);
                }
                break;
            }
        }
    }
    return tmp;
}
