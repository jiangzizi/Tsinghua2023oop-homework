# 简单计算图
题目描述

计算图描述了一种计算方式：一个计算图可以看做一个有向无环图，其中每个结点要么是一个常数(Constant)，要么是占位符(Placeholder)，要么是一个运算符(OperationNode)。一个常数结点入度为0，其值是一个可设定的常数。一个运算符结点入度为其运算数个数，其值为入结点经过该运算符运算后的值。

本题中要求你实现一个简单的运算图，支持常数和加法、减法两种运算符。例如：加法运算的结点入度为2，其值为两个运算符的和。

我们提供了计算图的结点类Node，运算符结点类Operator，计算图类Graph的定义，根据名字查找值的辅助类myMap，以及处理输入的main函数。请你完善其实现，并以其为基础实现加法、减法运算符。 在每次计算前，先要给占位符赋具体值，进而根据计算图得到其他节点的值。

文件下载地址：下载链接
输入样例

第一行是变量数n，节点数m，计算操作数q。

接下来n行是对变量的具体描述，每一行由变量名和变量属性组成。属性有两种: P表示该变量是 Placeholder ; C表示该变量是 Constant ，接下来的数字即为该变量的数值。

接下来m行每一行定义一个新节点，每行包含一个等号，等号左边是节点名称，等号 右边是得到新节点的计算过程。这些节点共同构成了一张计算图，通过输入不同的 x, y，可以反复计算图中的其他节点 a, b, c ...

接下来q行每一行是一个计算操作。每一行第一个元素是待计算结果的节点名称（待计算节点指最后一个出现的同名节点），第二个元素k表示接下来有 个类型为 Placeholder 的变量需要赋值，然后是k个赋值对，每个赋值对包括一个待赋值的 Placeholder 类型的变量和赋值的数值，每一行的计算操作根据给出的赋值输出一个计算结果。测试数据保证所有操作合法。

3 3 2
x P
y P
z C 3.0
a = x + y
b = a + x
a = x + z
EVAL a 2 x 2.0 y 1.0
EVAL b 2 x 2.0 y 1.0

输出样例

依次输出q个操作的计算结果，所有的计算结果保留2位小数。

5.00
5.00

对上面的样例的解释如下：

a = x(2.0) + z(3.0) = 5.00
b = a + x = ( x + y ) + x = ( x(2.0) + y(1.0) )+ x(2.0) = 5.0 

要求

    不能修改 node.h, graph.h, operation.h, operation.cpp, mymap.h, mymap.cpp, main.cpp
    完善 node.cpp, graph.cpp 中的实现
    可以增加cpp或h文件，用于编写加法、减法的类，并据此修改Makefile，生成的可执行文件名为main

提交格式

请将你的文件打包成一个 zip 格式的压缩包并上传。注意：你的文件应该在压缩包的根目录下，而不是压缩包的一个子文件夹下，换而言之，解压你提交的压缩包后，应该直接得到一系列 cpp 文件、h 文件等代码文件，而不是一个包含它们的文件夹。评测时，OJ会将提供的文件贴入你的目录下进行编译并执行。