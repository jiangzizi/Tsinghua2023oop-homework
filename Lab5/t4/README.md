# 动态多维数组
## 题目描述

C++的模板是一个强大的存在（指报错很多）。比如，我们可以使用模板推导，在编译时进行一些计算。

比如下面这个计算阶乘的程序：
```c++
#include <iostream>

template <int k>
struct Factorial {
    static const int value = k * Factorial<k-1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

int main()
{
    std::cout << Factorial<10>::value << std::endl; 
    return 0;
}
```
在一些编辑器中，当你把光标悬停在 
```c++
Factorial<10>::value
``` 上时，你会发现已经可以看到最终的计算结果，这是因为上面的结果并非在程序运行时得到的，而是在编译期得到的。

借助以上模板推导的思路，我们可以通过模板实现一个动态多维数组类（MultiDimArray）。

动态多维数组类需要实现一下 3 种功能：
### 1. 初始化

动态多维数组有两个最基本的属性：数据类型、维数，通过模板参数确定。

在初始化时，我们需要指定动态多维数组在不同维度上的初始大小，如：
```c++
using std::vector;
vector<int> init_1 = {2, 3, 4};
MultiDimArray<int, 3> arr_1(init_1);   // int 型的三维数组，大小为 2*3*4
vector<int> init_2 = {7};
MultiDimArray<float, 1> arr_2(init_2); // float 型的一维数组，大小为 7
```
保证初始化时所用 vector<int> 的大小和动态多维数组指定的维数一致。
### 2. 拷贝和移动

动态多维数组支持元素的拷贝和移动。

在这个过程中，数组的维数保持不变，但各个维度的大小可能改变（所谓“动态”）。例如，一个三维数组的初始尺寸是 3×3×33×3×3，虽然不能将其改成四维数组或二维数组，但是可以把它的尺寸改为 2×3×42×3×4。如：
```c++
using std::vector;
vector<int> init_3 = {2, 3, 4};
MultiDimArray<int, 3> arr_3(init_3);
MultiDimArray<int, 3> arr_4 = arr_3;    // 正确，arr_4 是 arr_3 的一个副本
// MultiDimArray<int, 4> arr_5 = arr_3; // 错误，维数不同不能复制或移动
MultiDimArray<int, 3> arr_5(init_3);
vector<int> init_6 = {3, 3, 3};
MultiDimArray<int, 3> arr_6(init_6);
arr_6 = std::move(arr_5);               // 正确，arr_6 尺寸变为 2*3*4
```
当然，你需要避免内存泄露的出现。
### 3. 元素的访问

和普通数组一样，动态多维数组支持使用下标运算符对数组中的元素进行访问（读和写），如：
```c++
int a = arr_6[0][1][2];
arr_6[0][1][2] = 1024;
```
你需要编写 multidimarray.hpp，在其中完成 MultiDimArray 类的实现。

为了便于你调试，我们提供了 capsule.hpp 和 main-for-show.cpp。

capsule.hpp 为检测程序正确性的辅助类，main-for-show.cpp 为数组维度为 3，数据类型为 int 时对应的示例 main.cpp。

文件下载地址：下载链接
## 输入说明

每个测试点的维数 k 和数据类型 TestDataType 由 main.cpp 指定。

输入的第一行包含一个正整数 n，表示需要创建的数组个数，后续的所有操作均在这些数组间进行。

接下来 n 行，每行包含 k 个整数 a1,…,ak​，用于初始化一个数组。其中 k 为本测试点制定的数组维数，ai​ 表示数组第 i 维的初始大小。

输入的第 n+2 行包含一个整数 m，表示操作数量。

接下来 m 行，每行以一个字符串开头，对应一个操作：

- copy i j：将第 ii 个创建的数组拷贝到第 jj 个初始创建的数组。（拷贝过程中应当出现数据元素的复制）
- move i j：将第 ii 个创建的数组移动到第 jj 个初始创建的数组。（移动过程中不应当出现数据元素的复制）
- assign i a1 ... ak p：将第 ii 个创建的数组下标为 [a1]…[ak][a1​]…[ak​] 位置的元素赋值为 p，其中 aiai​ 表示数组第 ii 维的元素下标，pp 为 TestDataType 类型。
- get i a1 ... ak：输出第 ii 个创建的数组下标为 [a1]…[ak][a1​]…[ak​] 位置的元素，其中 aiai​ 表示数组第 ii 维的元素下标。

## 输出说明

按照 get 指令的要求，依次输出数组元素。

浮点数保留 6 位小数，已包含在 main.cpp 中，只要正确地实现了对应的功能接口，即可得到正确输出。
样例输入
子任务 1:
```c++
3
1 2 3
2 3 1
3 1 2
9
assign 1 0 1 2 111
assign 2 1 2 0 222
assign 3 2 0 1 333
get 1 0 1 2
get 1 0 0 0
get 2 1 2 0
get 2 0 0 0
get 3 2 0 1
get 3 0 0 0
```
子任务 2:
```c++
3
1 2 3
2 3 1
3 1 2
10
assign 1 0 0 0 111
assign 2 0 0 0 222
assign 3 0 0 0 333
get 1 0 0 0
get 2 0 0 0
get 3 0 0 0
copy 1 2
get 2 0 0 0
move 1 3
get 3 0 0 0
```
## 样例输出
子任务 1:
```c++
111
0
222
0
333
0
sanity check: ok
```
子任务 2:
```c++
111
222
333
111
111
sanity check: ok
```
## 数据规模和约定

本题共设置 2 个子任务，各占 50 分，分别对应测试点 1-5 和 6-10。

- 子任务 1：初始化、元素访问（读和写）。
- 子任务 2：拷贝、移动。注意，测试中会使用元素访问功能。

对于所有测试点，保证 1≤n≤101≤n≤10，1≤m≤10001≤m≤1000。

对于赋值操作，保证设置的 pp 不会造成数据溢出。

每个测试点只检测某一固定维数的数组。

> 注意：在评测程序中使用名字为 DIM 的宏指定数组维度，请避免使用同名变量。
## 提交格式

仅需要提交 multidimarray.hpp 文件。

我们会将你提交的文件和预先设置好的 main.cpp，capsule.hpp，Makefile 一起编译运行。
