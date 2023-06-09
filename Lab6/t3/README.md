# 发年终奖
## 题目描述

某公司年终要给所有员工发奖金，按照职级的不同，有不同的基础年终奖金额；根据绩效的评估有不同的 bonus。该公司总共有3个职级：P1、P2、P3，其中 P1 基础年终奖金额为 2000 元，P2 的基础年终奖金额为 5000 元，P3 的基础年终奖金额为 10000 元。

绩效为任务的完成程度，按照绩效的大小，也有不同的 bonus 策略。绩效为0到1的小数，当绩效为 [0,0.5) 时，在已有的基础上增加 1000 元。当绩效为 [0.5,0.8) 时，年终奖增加金额为绩效乘以基础年终奖。当绩效为 [0.8,1.0] 时，年终奖增加金额为两倍的绩效乘以基础年终奖。
## 输入样例

第一行一个整数 n，代表需要计算年终奖金额的人数。

接下来 nn 行，每行一个字符串，一个小数，分别代表职级和绩效。
```c++
2
P1 0.3
P3 0.9
```
## 输出样例

n 个整数，表示每个人最终的年终奖金额。（如果为小数，则向下取整）
```c++
3000
28000
```
## 要求

- 不修改 main.cpp（main.cpp 在 这里下载）。
- 使用策略模式。
- 你需要提交多个文件，包含 Makefile，上述文件调用的各种头文件及其 cpp 文件。使用 Makefile 必须要能生成可执行文件 main（不带扩展名）。
- 你应该将你的文件打包成一个 zip 压缩包并上传。注意：你的文件应该在压缩包的根目录下，而不是压缩包的一个子文件夹下。
