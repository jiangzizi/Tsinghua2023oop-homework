#include<vector>
#include<iostream>
#include<functional>
template <typename T>
class MyQueriable
{
    private:
        std::vector<T> arr;
    public:
        MyQueriable(std::vector<T> _arr):arr(_arr){}
        int size()
        {
            return arr.size();
        }
        int sum()
        {
            T sum=0;
            for(auto i:arr)
            {
                sum+=i;

            }
            return sum;
        }
        T& operator[](const int x)
        {
            return arr[x];
        }
        MyQueriable where(std::function<bool(T)> fun)
        {
            std::vector<T> nowarr;
            for(int i=0;i<arr.size();i++)
            {
                if(fun(arr[i])==1)
                {
                    nowarr.push_back(arr[i]);
                }
            }
            return MyQueriable<T>(nowarr);
        }
        MyQueriable apply(std::function<T(T)> fun)
        {
            std::vector<T> nowarr;
            for(int i=0;i<arr.size();i++)
            {
                
                nowarr.push_back(fun(arr[i]));
                
            }
            return MyQueriable<T>(nowarr);


        }

};
template <typename T> 
MyQueriable<T> from(std::vector<T> arr)
{
    return MyQueriable<T>(arr);
}