#include <iostream>
#include "altset.h"
using namespace std;
Altset::Altset(const char *data, int len)
{

    gene = new bool[max(len + 1, 100)];
    nowlen = max(len + 1, 100);

    for (int i = 0; i < len; i++)
    {
        if (data[len - i - 1] == '1')
        {
            gene[i] = 1;
            sum++;
        }
        else
        {
            gene[i] = 0;
        }
    }
    this->length = len;
}
void Altset::inverse(int index)
{
    if (gene[index] == 1)
    {
        sum--;
        gene[index] = 0;
    }
    else
    {
        sum++;
        gene[index] = 1;
    }
}
void Altset::append(int value)
{
    if (nowlen < length + 2)
    {
        bool *arr = new bool[length + 1];
        nowlen=nowlen*2;
        for (int i = 0; i < length; i++)
        {
            arr[i] = gene[i];
        }
        length++;
        delete[] gene;
        gene = new bool[nowlen];
        for (int i = 0; i < length - 1; i++)
        {
            gene[i] = arr[i];
        }
        gene[length - 1] = value;
        delete[] arr;
    }
    else
    {
        length++;
        gene[length-1]=value;
    }
    if (value == 1)
    {
        sum++;
    }
}
bool Altset::get(int index) const
{
    return gene[index];
}
bool Altset::empty() const
{
    if (length == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Altset::count() const
{
    return sum;
}
