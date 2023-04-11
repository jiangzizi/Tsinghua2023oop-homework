机械加工厂
机械加工厂
题目描述

编写一个软件记录一个机械加工厂从部件生产到车辆组装、销售的整体流程。

已有 Wheel 和 Engine 两个类的源文件，需要编写下面几个类的具体程序：

Vehicle：机动车基类。每个机动车包含一个 Wheel 和一个 Engine 对象，通过组合来实现。

Motor：摩托车类，需通过继承 Vehicle 类实现。同时有其自身的功能。

Car：汽车类，需通过继承 Vehicle 类实现。

文件下载地址
输入样例

第一行包括一个正整数 nn，表示订单的个数。

接下来 nn 行，每一行有两个整数 a,ba,b 和一个字符串 cc 组成。

aa 表示生产的类别，00 为 Vehicle，11 为 Motor，22 为 Car。

bb 表示轮胎的个数，cc 代表引擎的名称。

3
0 3 Magic
1 2 Diesel
2 4 Gasoline

输出样例

按照输入顺序，依次输出每个订单的组件生产和装配过程。

第一行输出使用的引擎名称。

第二行输出使用的轮胎个数。

第三行在构造 Vehicle、Motor 和 Car 类时输出使用这些部件组装的过程，注意 vehicle、motor 和 car 名称的区别。

第四行通过 describe 函数输出描述，注意 vehicle、motor 和 car 名称的区别。

对于 Motor 类来说，第五行通过调用 sell 函数输出固定字符串 A motor is sold!。

Using Magic engine.
Building 3 wheels.
Finish building a vehicle with 3 wheels and a Magic engine.
A vehicle with 3 wheels and a Magic engine.
Using Diesel engine.
Building 2 wheels.
Finish building a motor with 2 wheels and a Diesel engine.
A motor with 2 wheels and a Diesel engine.
A motor is sold!
Using Gasoline engine.
Building 4 wheels.
Finish building a car with 4 wheels and a Gasoline engine.
A car with 4 wheels and a Gasoline engine.

要求

    不修改 main.cpp、engine.h/cpp、wheel.h/cpp。
    在已有代码基础上编写 Vehicle 类，Motor 类，Car 类。
    我们将会使用 g++ main.cpp car.cpp motor.cpp vehicle.cpp wheel.cpp engine.cpp -o main 命令来编译得到可执行文件 main。

限制与约定

2≤n≤1002≤n≤100

0≤a≤20≤a≤2

1≤b≤101≤b≤10

cc 的长度不超过 2020
提交格式

根据提供的文件的内容，编写对应的类的代码（Vehicle 类，Motor 类，Car 类）。

请将你的文件打包成一个 zip 格式的压缩包并上传。注意：你的文件应该在压缩包的根目录下，而不是压缩包的一个子文件夹下，换而言之，解压你提交的压缩包后，应该直接得到一系列 cpp 文件、h 文件等代码文件，而不是一个包含它们的文件夹。评测时，OJ会将提供的文件贴入你的目录下进行
