#include <iostream>
using namespace std;
template <typename T>
class my_ptr
{
private:
    T *p;
    static T *q;

public:
    my_ptr(T *t0)
    {
        // q=new T(10);
        cout << "my_ptr constructed." << endl;
        p = t0;
    }
    my_ptr()
    {
        // q=new T(10);
        cout << "my_ptr constructed." << endl;
        // p=t0;
        p = nullptr;
    }
    ~my_ptr()
    {

        cout << "my_ptr destructed." << endl;
        if (p != nullptr)
        {
            delete p;
        }
    }
    my_ptr(const my_ptr &p0) // 拷贝构造
    {
        p = new T();
        cout << "Copying of my_ptr is forbidden!" << endl;
        cout << "my_ptr constructed." << endl;
    }
    my_ptr(my_ptr &&p0) // 移动构造
    {
        delete p;
        p = p0.p;
        p0.p = nullptr;
        cout << "my_ptr constructed." << endl;
    }
    my_ptr &operator=(const my_ptr &right) // 拷贝赋值
    {
        cout << "Copying of my_ptr is forbidden!" << endl;
        cout << "my_ptr updated." << endl;
        return *this;
    }
    my_ptr &operator=(my_ptr &&right) // 移动赋值
    {
        delete p;
        this->p = right.p;
        right.p = nullptr;
        cout << "my_ptr updated." << endl;
        return *this;
    }
    T &operator*()
    {
        if (p == nullptr)
        {
            cout << "Do not attempt to read a nullptr!" << endl;
            return *q;
        }
        return *p;
    }
    T *operator->()
    {
        if (this->p == nullptr)
        {
            cout << "Do not attempt to read a nullptr!" << endl;
            return q;
        }
        return p;
    }
};
template <typename T>
T *my_ptr<T>::q = new T();