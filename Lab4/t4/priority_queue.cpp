#include "priority_queue.h"
#include"point.h"
#include <iostream>
using namespace std;
template <class T>
PriorityQueue<T>::~PriorityQueue() {}
template <class T>
PriorityQueue<T>::PriorityQueue(AbstractCompare<T> *_cmp)
{
    mysize=0;
    cmp = _cmp;
}
template<> 
PriorityQueue<int>::PriorityQueue(AbstractCompare<int> *_cmp)
{
    mysize=0;
    cmp=_cmp;
}
template<>
PriorityQueue<int>::~PriorityQueue()
{}
template<> 
PriorityQueue<Point>::PriorityQueue(AbstractCompare<Point> *_cmp)
{
    mysize=0;
    cmp=_cmp;
}
template<>
PriorityQueue<Point>::~PriorityQueue()
{}

template <>
void PriorityQueue<int>::push(int element)
{
    int t = mysize;
    for (int i = 0; i < mysize; i++)
    {
        if (cmp->compare(element, arr[i]) == 0)
        {
            t = i;
            break;
        }
    }
    mysize++;
    for (int i = mysize - 1; i >= t + 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[t] = element;
}
template <>
void PriorityQueue<Point>::push(Point element)
{
    int t = mysize;
    for (int i = 0; i < mysize; i++)
    {
        if (cmp->compare(element, arr[i]) == 0)
        {
            t = i;
            break;
        }
    }
    mysize++;
    for (int i = mysize - 1; i >= t + 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[t] = element;
}
template <>
int PriorityQueue<int>::size()
{
    return mysize;
}
template <>
int PriorityQueue<Point>::size()
{
    return mysize;
}
template <>
void PriorityQueue<int>::pop()
{
    for (int i = 0; i <= mysize - 2; i++)
    {
        arr[i] = arr[i + 1];
    }
    mysize--;
}
template<>
void PriorityQueue<Point>::pop()
{
    for (int i = 0; i <= mysize - 2; i++)
    {
        arr[i] = arr[i + 1];
    }
    mysize--;
}
template <>
bool PriorityQueue<int>::empty()
{
    return (mysize == 0);
}
template <>
bool PriorityQueue<Point>::empty()
{
    return (mysize == 0);
}
template <>
int PriorityQueue<int>::top()
{
    return arr[0];
}
template <>
Point PriorityQueue<Point>::top()
{
    return arr[0];
}
