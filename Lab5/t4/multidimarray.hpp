#pragma once
#include <vector>
#include <iostream>
#include <typeinfo>
std::vector<int> count;
template <typename T, unsigned size>
class MultiDimArray
{
public:
    MultiDimArray<T, size - 1> *p;
    int dim;
    MultiDimArray(std::vector<int> t)
    {
        count = t;
        dim = count[0];
        p = new MultiDimArray<T, size - 1>[dim];
    }
    MultiDimArray()
    {
        dim = count[count.size() - size];
        p = new MultiDimArray<T, size - 1>[dim];
    }
    MultiDimArray<T, size - 1> &operator[](int i)
    {
        return p[i];
    }
    virtual ~MultiDimArray()
    {
        delete[] p;
    }
    MultiDimArray<T, size> &operator=(const MultiDimArray<T, size> &right)
    {
        delete[] p;
        dim = right.dim;
        this->p = new MultiDimArray<T, size - 1>[dim];
        for (int i = 0; i < dim; i++)
        {
            this->p[i] = (right.p[i]);
        }
        return *this;
    } // TODO
    MultiDimArray<T, size> &operator=(MultiDimArray<T, size> &&right)
    {
        delete[] p;
        dim = right.dim;
        this->p = new MultiDimArray<T, size - 1>[dim];
        for (int i = 0; i < dim; i++)
        {
            this->p[i] = std::move(right.p[i]);
        }
        right.dim = 0;
        return *this;
    }
};
template <typename T>
class MultiDimArray<T, 1>
{
public:
    T *p;
    int dim;
    MultiDimArray()
    {
        dim = count[count.size() - 1];
        p = new T[count[count.size() - 1]];
    }
    T &operator[](int i)
    {
        return p[i];
    }
    MultiDimArray<T, 1> &operator=(const MultiDimArray<T, 1> &right)
    {
        delete[] this->p;
        dim = right.dim;
        this->p = new T[dim];
        for (int i = 0; i < dim; i++)
        {
            this->p[i] = right.p[i];
        }
        return *this;
    }
    MultiDimArray<T, 1> &operator=(MultiDimArray<T, 1> &&right)
    {
        delete[] p;
        dim = right.dim;
        this->p = new T[dim];
        for (int i = 0; i < dim; i++)
        {
            this->p[i] = right.p[i];
        }
        delete []right.p;
        right.p = nullptr;
        right.dim = 0;
        return *this;
    }
    ~MultiDimArray()
    {
        delete[] p;
    }
};