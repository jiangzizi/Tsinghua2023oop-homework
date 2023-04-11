#include <iostream>
#include <vector>
using namespace std;
class Rack
{
public:
    friend ostream &operator<<(ostream &out, const Rack &tmp);
    friend int operator<(const Rack &a, const Rack &b);
    friend int operator>(const Rack &a, const Rack &b);
    friend int operator==(const Rack &a, const Rack &b);
    int operator()(int t)
    {
        int sum=0;
        for(int i=0;i<num;i++)
        {
            if(arr[i]==t)
            {
                sum++;
            }
        }
        return sum;
    }
    void operator~()
    {
        Rack tmp(num);
        for (int i = 0; i < tmp.num; i++)
        {
            tmp.arr.push_back(arr[num - 1 - i]);
        }
        for (int i = 0; i < tmp.num; i++)
        {
            arr[i]=tmp.arr[i];
        }

    }
    friend Rack operator,(const Rack &a, const Rack &b);
    friend Rack operator,(int a, const Rack &b);
    friend Rack operator,(const Rack &a, int b);
    friend Rack operator&(const Rack &a, const Rack &b);
    Rack operator--(int)
    {
        Rack tmp(num);
        for (int i = 0; i < num; i++)
        {
            tmp.arr.push_back(arr[i]);
        }
        arr.pop_back();
        num--;
        return tmp;
    }
    Rack &operator--()
    {
        num--;
        for (int i = 0; i < num; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr.pop_back();
        return *this;
    }

    int num;
    Rack(int t = 0)
    {
        num = t;
    }
    vector<int> arr;
    Rack operator+=(int a)
    {
        // cout<<num;
        // cout<<a<<endl;
        num++;
        arr.push_back(a);
        return *this;
    }
    Rack operator+=(const Rack &n)
    {
        // cout<<endl<<n.arr[1]<<n.arr[2]<<n.arr[3];
        // cout<<endl<<num;
        for (int i = 1; i <= n.num; i++)
        {
            arr.push_back(n.arr[i - 1]);
            // cout<<arr[i];
        }
        num = num + n.num;
        // cout<<arr[num]<<"!";
        return *this;
    }
};