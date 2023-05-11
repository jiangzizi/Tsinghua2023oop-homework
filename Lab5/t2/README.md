# 函数计算器
## 题目描述

小明在计算函数值时发现很多函数都可以使用C++来实现，而cmath头文件中提供了大量实用的数学函数，在做数学题的他想偷偷懒，于是编写了一个函数类，并且自己实现了一个指数函数类。他现在又想偷懒了，于是找到了你，希望你完善一次函数、组合函数、复合函数的实现。

文件下载地址：下载链接


## 输入样例

第一行包括一个正整数 n

后面会跟相应的函数构造

对于n的解释如下

0 代表构造常值函数后面会跟一个浮点数 c，如：
```c++
0
1.5
```
表示构造了一个

f(x)=1.5这样的常量（ConstFunc）函数

1代表构造线性函数，后面会跟两个浮点数 a, b 表示构造一个 y=ax+b 这样的函数，如：
```c++
1
3.3 1.2
```
构造了一个 f(x)=3.3x+1.2 这样的线性（LinearFunc）函数

2 代表构造指数函数，后面会跟一个浮点数 b 表示构造一个 y=bx 这样的函数，如：
```c++
2 
2.5
```
构造了一个f(x)=${2.5^x}$这样的指数（ExpFunc）函数

3 代表构造一个复合函数。后面会跟两组构造（这个构造过程可能是递归的，复合函数再复合）

先构造内层函数 g(x)，再构造外层函数 f(x)

如：
```c++
3
2
1.2
1
1.6 2.5
```
其中
```c++
2
1.2
```
表示构造了一个$g(x)=1.2x$这样的指数函数
```c++
1
1.6 2.5
```
表示构造了一个 $f(x)=1.6x+2.5$ 这样的线性函数

复合起来就是 $f(g(x))=1.6×1.2x+2.5$

4 代表构造一个组合函数，下面会跟两个浮点数 a, b
```c++
4
3.3 4.4 // a b
2       // 指数函数
1.2     // f(x) = 1.2^x
0       // 常值函数
1.6     // g(x) = 1.6
```
得到的函数就是 $h(x)=a⋅f(x)+b⋅g(x)$

这个例子中为 $h(x)=3.3×1.2x+4.4×1.6$

接下来有一个正整数 m，表示有 m 个点需要求这个函数的函数值，接下来一行有 m 个浮点数
```c++
4
0.1 2.2 3.3 4.4
```
虽然有这么多个不同的构造，你会发现实际上我们得到了一个函数

它可能由多个函数复合或组合起来而成

你可以看下面的例子
## 样例1

### 输入
```c++
1
1.2
3.3
4
0 1.1 2.2 3.3
```
这里构造了一个线性函数$f(x)=1.2x+3.3$

有4个测试点
```c++
0 1.1 2.2 3.3
```
### 输出

结果已经自动保留了5位小数
```c++
3.30000
4.62000
5.94000
7.26000
YES
```
最后一行YES代表代码会检测你的程序不存在内存泄露，如果存在则会输出NO
## 样例2

### 输入
```c++
3
3
1
1.2 3.3
2
5.2
1
1.6 2.8
3
1.1 2.2 3.3
```
样例解释：

这个样例构造了一个经过两次复合得到的函数

第一行3表示最终我们要的函数我们记作 $h(x)$，他由 $f(x)$ 和 $g(x)$ 复合而成，$h(x)=f(g(x))$

第二行表示我们构造内层的函数 $g(x)$，他是一个复合函数由下面4行的函数复合而成

$记 g(x)=u(w(x))$

第3、4行构造了一个线性函数$w(x)=1.2x+3.3$

第5、6行构造了一个指数函数$u(x)=5.2x$

复合得到的结果即 $g(x)=u(w(x))=5.21.2x+3.3$

第7、8行构造了一个线性函数 $f(x)=1.6x+2.8$

最外层复合的结果即为 $f(g(x))=1.6×(5.21.2x+3.3)+2.8$

最终3个测试点为1.1 2.2 3.3

### 输出
```c++
3254.08792
28656.44288
252527.72887
YES
```
## 要求
```
    不修改 main.cpp expfunc.h constfunc.h。
    如果你增加了其他的.cpp文件请相应修改Makefile
    补充完整combfunc.h compfunc.h func.h linearfunc.h
    防止出现内存泄漏，否则答案也将视为错误
```
## 限制与约定

    计算过程中结果不会超出 double 能表示的范围

    时间限制：1s

    空间限制：256MB
## 提交格式

    根据提供的压缩包内的内容，补充相应的代码（ combfunc.h compfunc.h func.h linearfunc.h）。
    你应该将你的文件打包成一个zip压缩包并上传。评测时，OJ会将提供的 main.cpp constfunc.h expfunc.h贴入你的目录下进行编译并执行。注意：你的文件应该在压缩包的根目录下，而不是压缩包的一个子文件夹下。

## 评分标准

    OJ评分占100%

    


## 本人评价
    看起来不难，做起来也一样。需要逐渐习惯虚函数机制的运用。最核心的考察点（YES）实质上就是考虚的析构函数的作用。其他代码就仿照expfunc类写出就行。