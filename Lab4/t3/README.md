# 智能指针
题目描述

指针是C语言的重要概念，也是很容易造成bug的功能，同学们在日常编写程序的过程中应该都遇到过内存泄露、访问非法内存等错误。

事实上，在C++的标准模板库中提供了一些智能指针类，例如你今天要模仿的unique_ptr。它实际上是一个封装好的指针，可以帮助你管理内存，并且不需要你操心内存的释放。

具体而言，unique_ptr指向一块内存，这块内存应当是由这个unique_ptr来唯一管理的。一方面，不允许通过拷贝构造、拷贝赋值等方式让两个unique_ptr指向同一块内存；另一方面，当unique_ptr被析构时，它需要释放掉它指向的内存。可以通过移动赋值和移动构造在两个unique_ptr间交接一块内存的管理权。

你需要编写一个my_ptr模板类，来实现unique_ptr的基本功能，具体包括：

    内存管理。你的my_ptr应该可以管理一块内存，并在析构时释放内存；通过修改拷贝构造函数和赋值运算符来禁止其他的my_ptr管理同一块内存；通过修改移动构造函数和赋值运算符来允许在两个my_ptr之间交接内存管理权。为了通过编译，不应该通过delete来禁止拷贝，如果试图拷贝构造，应当输出提示信息（见输出样例）并构造出一个空的my_ptr；如果试图拷贝赋值，应当输出提示信息（见输出样例）并保持被赋值的my_ptr不变。
    重载运算符。你的my_ptr需要支持指针的*和->两种运算符。

此外，你的my_ptr还需要有一些新的功能来防止一些常见的bug，包括：

    保护空指针。当试图利用*或->运算符访问一个空的my_ptr时，你应该进行一些修改来防止Segmentation fault的发生。具体而言，你可以使用一个静态指针来指向一块内存区域，作为访问空my_ptr时返回的“垃圾桶”。这块区域不需要被释放，可以让它在程序结束时被自动释放，检测内存泄漏时不会考虑它。

main.cpp已经写好，你不应该修改它。你需要自己完成my_ptr.h来实现题目要求你实现的功能。

下载地址：点此下载

测试点分为4个子任务：

    测试内存管理
    测试移动构造和赋值，以及拷贝构造和拷贝赋值是否被禁用
    测试运算符重载以及空指针保护
    综合测试

你可以分别实现以获得不同分数。
输入格式

无输入，请参考下载文件的main.cpp
输出格式

当my_ptr构造或析构时，你需要输出一行形式为my_ptr constructed.或my_ptr destructed.的信息。

当调用赋值运算符时，你需要输出一行形式为my_ptr updated.的信息。

当调用应当被禁止的拷贝构造函数/赋值运算符时，你需要输出一行Copying of my_ptr is forbidden!的提示信息，在上面两条基础信息之前。

当尝试访问空指针时，你需要输出一行Do not attempt to read a nullptr!的提示语句。

例如子任务2的输出：

my_ptr constructed.
Copying of my_ptr is forbidden!
my_ptr constructed.
my_ptr constructed.
Copying of my_ptr is forbidden!
my_ptr constructed.
my_ptr constructed.
my_ptr destructed.
my_ptr destructed.
my_ptr destructed.
my_ptr destructed.
my_ptr destructed.
Accepted!

提示

本题分为了4个 subtask，每个 subtask 各占25分。你可以分别实现来得到部分分数，除了提供的main.cpp里的测试点，每个子任务还各有一个隐藏测试点，你需要都通过才能获得这个子任务的分数。四个 subtask 对应的测试点编号分别为：(1,5)，(2,6)，(3,7)，(4,8)。
要求

    不能修改main.cpp
    增加myptr.h，编写一个my_ptr模板类来实现题目要求的功能

提交格式

请将你的文件打包成一个 zip 格式的压缩包并上传。注意：你的文件应该在压缩包的根目录下，而不是压缩包的一个子文件夹下，换而言之，解压你提交的压缩包后，应该直接得到一系列 cpp 文件、h 文件等代码文件，而不是一个包含它们的文件夹。评测时，OJ会将提供的文件贴入你的目录下进行编译并执行。
