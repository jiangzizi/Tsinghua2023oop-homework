#include <iostream>
#include <list>
#include <vector>
#include "compare.h"
#include "sortlevel.h"
#include<functional>
using namespace std;

Compare<vector<int> > make_comp(list<sort_level> sortlevels)
{
    std::vector<std::function<bool(std::vector<int> a, std::vector<int> b)> >funlist;
    int key=sortlevels.size();
    //std::cout<<sortlevels.front().column<<"!!!";
    for(int i=0;i<key;i++)
    {
        auto f=sortlevels.front();
        sortlevels.pop_front();
        if(f.order==ASCEND)
        {
            int col=f.column-1;
            //std::cout<<col<<"!";
            auto tmpfun= [=](std::vector<int> l, std::vector<int> r) { return l[col] < r[col]; };
            funlist.push_back(tmpfun);
        }
        else
        {
            int col=f.column-1;
            //std::cout<<col<<".";
            //auto t=std::function<bool(int l, int r)> {return l<r};
            auto tmpfun= [=](std::vector<int> l, std::vector<int> r) { return r[col] < l[col]; };
            funlist.push_back(tmpfun);
        }
    }
    
    return Compare<std::vector<int> >(funlist);
}
