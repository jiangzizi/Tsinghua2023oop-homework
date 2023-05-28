# 多重排序
## 任务1

很多时候排序仅仅靠一个关键字是不够的。例如考试排名，首先按总分降序排列；如果总分相同，再按照语文成绩降序排列；如果语文成绩也相同，再按照数学成绩降序排列……

本题希望你能编写一个Compare函数对象，能够结合多个关键字进行排序。

首先我们来考虑一个具体的问题。给定n个3维点(x,y,z)，按x坐标从小到大排序；如果x坐标相同，则按y坐标从小到大排序；如果仍相同，则按z坐标从小到大排序。例如以下代码：
```c++
class Point {
    public:
    int x, y, z;
};
vector<Point> v;
// insert some points into v ...
auto xcomp = [](Point l, Point r) { return l.x < r.x; };
auto ycomp = [](Point l, Point r) { return l.y < r.y; };
auto zcomp = [](Point l, Point r) { return l.z < r.z; };
Compare<Point> comp = { xcomp,ycomp,zcomp };
sort(v.begin(),v.end(),comp);
```
其中xcomp, ycomp, zcomp 是lambda表达式，你可以认为它们就是用来比较point的x、y、z坐标的函数。（如果你想知道lambda表达式的更多内容，请查看这里。）

对于Compare<Point> comp = { xcomp,ycomp,zcomp };，这里使用了std::initializer_list作为 Compare<Point> 构造函数的参数类型，可以参考这里获得更多的相关知识。
## 任务2

在上面的一段代码里，我们完成了一个n行3列的表的一个多重排序：先按第一列升序，再按第二列升序，再按第三列升序。我们能否稍微拓展一些呢？

现在对于一个m行n列的表，你需要按用户指定的顺序进行多重排序（类似于Excel中的自定义排序）

为了方便排序顺序的指定，定义一个enum和一个struct如下：
```c++
enum order_type {ASCEND,DESCEND};  // ASCEND表示按升序排列，DESCEND表示按降序排列
struct sort_level {
    int column;      // 排序的是第几列（列编号从1开始）
    order_type order;     // 是升序还是降序
};
```
其中sort_level的column成员的编号从1开始。

这样我们可以通过一个std::list<sort_level>来指定多重排序的顺序，例如：
```c++
std::list<sort_level> sortlevels = { {1,DESCEND},   // 首先按第1列降序排列
{3,DESCEND},   // 然后按第3列降序排列
{4,ASCEND} };  // 最后按第4列升序排列
```
现在，对于一个m行n列的vector<vector<int>>，你需要编写一个make_comp函数作为std::sort的比较器，按照指定的顺序进行多重排序，例如下面的代码：
```c++
vector<vector<int>> v;
// 定义一个5行4列的vector
v={{1,2,3,4},
   {0,2,3,4},
   {1,2,4,4},
   {1,2,3,3},
   {1,2,2,5}};
std::sort(v.begin(), v.end(), make_comp(sortlevels));  // 用上面的sortlevels进行多重排序
/* 此时v的值应该为
{{1,2,4,4},
 {1,2,3,3},
 {1,2,3,4},
 {1,2,2,5},
 {0,2,3,4}}
*/
```
注意：你的make_comp函数应该通过前面编写的Compare类来实现。具体来说，你的make_comp函数应该返回一个Compare<vector<int>>作为std::sort的比较器， 也即，make_comp的声明已经规定为：
```c++
Compare<vector<int>> make_comp(std::list<sort_level>);
```
## 评测信息

本题分为两个 Subtask，其中 Subtask1 是对 Point 的排序，Subtask2是对表的排序。

总共有10个测试点。前4个为 Subtask1，后6个为 Subtask2。
下发的文件

本题所需的文件可以从这里下载
## Subtask1 评测方式

通过文件中 main_subtask1.cpp 进行测试。你不应修改 main_subtask1.cpp 的内容；你应该编写 compare.h 完成题目要求。OJ编译时通过命令g++ main_subtask1.cpp -std=c++11 -o main1进行编译
## 输入格式

第一行为一个整数n，表示总共有多少个点。 后n行，每行有3个用空格隔开的数字，分别代表点的x/y/z坐标
## 输出格式

输出n行，为排序后的点
## 输入样例
```c++
3
1 1 1
1 0 1
1 1 0
```
## 输出样例
```c++
1 0 1
1 1 0
1 1 1
```
## 数据范围

1≤n≤1001≤n≤100，x、y、z坐标在int范围内
Subtask2 评测方式

通过文件中 main_subtask2.cpp 进行测试。你不应修改 main_subtask2.cpp 的内容；你应该编写 sort.cpp 完成题目要求。编译时通过命令g++ main_subtask2.cpp sort.cpp -std=c++11 -o main2进行编译
## 输入格式

第一行为3个数字m,n,d，表示表格有m行n列，多重排序有d条指令 随后m行，每行n个整数，表示这个m行n列的表格 随后d行，每行开头是一个数字k，表示要排序的是第k列（列编号从1开始）；随后是一个字母，如是a，代表这一列升序排列；如是d，代表这一列降序排列。
## 输入样例
```c++
5 4 3                                // 表5行4列；多重排序有3个指令
1 2 3 4
0 2 3 4
1 2 4 4
1 2 3 3
1 2 2 5
1 d                              // 首先按第1列降序排列
3 d                            // 然后按第3列降序排列
4 a                               // 最后按第4列升序排列
```
## 输出样例
```c++
1 2 4 4
1 2 3 3
1 2 3 4
1 2 2 5
0 2 3 4
```
## 数据范围

1≤m,n≤1001≤m,n≤100，表格数字在int范围内 1≤d,k≤n1≤d,k≤n 数据保证kk不重复
提交方式

- 你需要提交 compare.h 和 sort.cpp。
- 你应该将你的文件打包成一个zip压缩包并上传。注意：你的文件应该在压缩包的根目录下，而不是压缩包的一个子文件夹下。
- Subtask1 只会用到 compare.h，并不会用到 sort.cpp。Subtask2 会同时用到 compare.h 和 sort.cpp。
