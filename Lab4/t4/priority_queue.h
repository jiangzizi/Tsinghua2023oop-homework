#pragma once
#include "abstract_compare.h"

template<class T> class PriorityQueue {
public:
    AbstractCompare<T> *cmp;
    int mysize;
    T arr[105];
    PriorityQueue(AbstractCompare<T> *_cmp);
    ~PriorityQueue();
    bool empty();
    int size();
    void push(T element);
    void pop();
    T top();
};