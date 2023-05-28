# 容器的可查询化
## 题目描述

请在头文件 myqueriable.h 中，实现一个序列容器的模板类 MyQueriable。它需要支持：

- 使用 obj.size() 得到容器的长度
- 使用 obj[i] 访问第i个元素

同时需要支持 where、apply、sum 三个成员函数。其中：

- where 接受一个函数对象 f 作为参数，返回值为 {x|f(x)==true, x 属于原来的 MyQueriable} 表示的 MyQueriable（元素顺序与原来的 MyQueriable 一致）；
- apply 以一个函数对象 f 作为参数，返回值为 {f(x)|x 属于原来的 MyQueriable} 表示的 MyQueriable（元素顺序与原来的 MyQueriable 一致）；
- sum 不带参数，返回值为 MyQueriable 中各元素之和。

此外，你还需要实现模板函数 from：

- 它以一个 std::vector 为参数，返回值为对应的 MyQueriable

提交注意事项：你只需要提交 myqueriable.h 文件即可，请不要提交压缩包。请直接使用 OJ 的“上传文件”按钮，而不是将文件内容粘贴至 OJ 的编辑器中。

## 示例1：
```c++
#include<iostream>
#include"myqueriable.h"

using namespace std;

bool op1(int x){return x > 2 && x < 10;}
class Op2{
public:
    int operator()(int x) {return x * 2;}
}op2;

int main(){
    vector<int> arr = {1, 4, 6, 2, 10};
    auto out = from(arr)
        .where(op1)  // 4, 6
        .apply(op2)  // 8, 12
        .sum();
    cout << out << endl;
}
```
## 示例1输出：
```c++
20
```
## 示例2：
```c++
#include<iostream>
#include<vector>
#include<cmath>
#include<functional>
#include"myqueriable.h"

using namespace std;

float opfn(float x){return sqrt(x);}
function<float(float)> op = opfn;

int main(){
    vector<float> vec = {2.0, 3.0, 4.0, 5.0};
    auto li = from(vec)
        .apply(op);
    for(int i = 0; i < li.size(); i++){
        cout << li[i] << endl;
    }
}
```
## 示例2输出：
```c++
1.41421
1.73205
2
2.23607
```
## 数据说明

1. 我们保证测试中不会出现 MyQueriable 对象中长度为 0 的情况；
2. apply、sum 返回值的元素类型应和原 MyQueriable 的元素类型相同：例如原来是 int，sum 的返回值也该是 int。
3. 为了避免浮点误差，本题的测试中不包含 float 等浮点数类型。

## 测试点

一共设置 6 个测试点。为了方便同学调试，我们提供了前 4 个测试点作为补充样例（下载链接）。


1. (20 分）只包含 from(std::vector<int>)，MyQueriable::sum，MyQueriable::size，以及 MyQueriable 的下标访问。
1. （20 分）在测试点 1 要求的基础上，额外包含 MyQueriable::where。
2. （20 分）在测试点 1 要求的基础上，额外包含 MyQueriable::apply。
4.（20 分）在测试点 1 要求的基础上，额外包含 MyQueriable::where，MyQueriable::apply。
5. （10 分，隐藏测例）与测试点 4 要求一致。
6. （10 分，隐藏测例）在测试点 4 要求的基础上，额外包含 from(std::vector<long long>)。

最朴素的实现即可通过本题的所有测试点，不需要考虑优化时间效率或空间效率。
