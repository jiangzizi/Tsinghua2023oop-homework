# 文本编辑器
## 题目描述

有了STL的帮助，我们可以做出很多东西。这次让我们来做一个简单的文本编辑器TextEditor。它的行为和一般的文本编辑器基本一致，如windows自带的记事本、vscode等。如有困惑，可在这些编辑器上尝试以作参考，但一切请以题目描述为准。

TextEditor的基本构成有：

- 文本：被编辑的对象。文本可以被加载到TextEditor内部进行操作，也可以由TextEditor输出。

- 光标：指示正在进行编辑的位置，由行号和列号确定，即(row, col)。为方便起见，一切编号从0开始，同时约定：
    - 对于一个nn行的文件，其合法行号为[0,n)[0,n)；
    - 对于有kk个字符的一行，其合法列号为[0,k][0,k]。当列号为0时，意味着位于该行第一个字符上；当列号为kk时，意味着位于该行最后的换行符上。

    举例如下：
    ```c++
    abc
    hello
    ```
    (0,0)(0,0)即为字符a的位置，(1,5)(1,5)即为o之后换行符的位置。

TextEditor具有以下功能：

- 创建：
    - 构造函数（TextEditor）：创建编辑器。初始状态下，文本为空（即没有任何文本，打印的时候表现为一个空行），光标位置为(0,0)(0,0)（即光标在这个空行的开头），处于非选中状态。

- 光标：

    * 选择（SELECT）：接受两个位置beg、end，选中[beg,end)区域，以便进一步编辑。需要注意，空行包含一个换行符，被选中时应将其包含。在beg、end相等时，选中区域为空，此时是有选中区域的状态，选中的区域为空字符串。

    * 移动光标（MOVE）：接受一个位置beg，移动光标至该位置。若当前有选中区域，则先取消选中状态再移动光标。

- 编辑：

    - 写入（WRITE）：接受一个字符串data，若无选中区域，则在光标处写入该字符串；若有选中区域，则替换之，即先删除再写入。写入完成后，光标均移动至写入内容末尾。例如：
    ```c++
        // 初始
        *abc
        // 写入hello
        hello*abc
    ```
    ```c++
    // 初始
    *ab*c
    // 写入hello
    hello*c
    ```
    - 换行（NEWLINE）：在光标所在行下方新插入一行，若无选中区域，则将光标所在行光标之后的字符移动至新行；若有选中区域，则先删除再换行。换行后，光标位于新一行开头。例如：
    ```c++
    // 初始
    abc*
    // 换行
    abc
    *
    ```
    ```c++
    // 初始
    *ab*c
    // 换行

    *c
    ```
    - 删除（DELETE）：若无选中区域，则删除光标位置的一个字符，光标位置不变；若有选中区域，则删除已选中的内容，同时退出选中状态，光标置于选中区域靠近开头的位置。光标位于行末时，将会删除行末换行符，将其与下一行合并；而若光标位于最后一行行末，则不会有任何操作。例如：
    ```c++
    // 初始
    *abc
    // 删除后
    *bc
    ```
    ```c++
    // 初始
    *ab*c
    // 删除后
    *c
    ```
    ```c++
    // 初始
    ab
    c*
    d
    // 删除后
    ab
    c*d
    ```

    - 复制（COPY）：如果有选中区域，复制选中区域的内容至剪贴板，如果剪切板之前有内容则覆盖之。若无选中区域，则无任何影响。例如：
    ```c++
    ab*c

    *hello
    ```
    // 执行复制，复制后的剪贴板内容如下（注意，复制了两个换行符）：
    ```c++
    c

    ```
    - 粘贴（PASTE）：若无选中区域，将剪贴板现有内容粘贴到光标处；若有选中区域，则替换之，即先删除再粘贴。剪贴板为空时不产生任何写入操作，但是可以将选中区域清除。在粘贴完成后，光标移动到粘贴内容末尾。例如：
    ```c++
    // 初始（剪贴板内容如上）
    ab*c

    hello
    // 粘贴后
    abc

    *c

    hello
    ```
    ```c++
    // 初始（剪贴板内容如上）
    ab*c*

    hello
    // 粘贴后
    abc

    *

    hello
    ```

    - 截屏（SCREEN）：将目前文本编辑器处理得到的文本逐行输出至标准输出。用*标出光标的位置或选中区域的位置。如：

    光标在(0,2)(0,2)处：
    ```c++
    ab*c

    hello
    ```
    选中区域为[(0,0),(1,0))[(0,0),(1,0))：
    ```c++
    *abc
    *
    hello
    ```
## 输入输出格式

输入的第一行包含一个正整数 m ，表示操作数量；

接下来输入m行，每行先输入一个字符串op，为上述功能的其中之一：

    对于光标移动操作：再输入两个正整数row、col，代表光标移动的位置，保证光标的位置合法；
    对于选择操作：再输入四个正整数row1、col1、row2、col2，代表选择区域的起始、终止位置，保证终止位置不小于起始位置且这两个位置合法；
    对于写入操作：再输入一个字符串data，代表写入的字符串，保证该字符串不为空且不包含换行符；
    对于其他操作：没有其他的输入。

对于每个截屏操作，将目前文本编辑器处理得到的文本逐行输出。
## 数据规模与约定

    对10%的数据，仅存在创建、写入、换行、删除、光标相关操作和截屏操作，不涉及选中状态下写入/换行/删除；
    对另外50%的数据，不涉及选中状态下粘贴；
    对100%的数据，m<=200m<=200，每次新增的字符串长度不超过60。

## 样例

### 样例1

输入：
```c++
23
SELECT 0 0 0 0
SCREEN
WRITE helloworld
SCREEN
NEWLINE
SCREEN
MOVE 0 10
DELETE
SCREEN
MOVE 0 0
SCREEN
DELETE
SCREEN
WRITE h
SCREEN
SELECT 0 0 0 5
SCREEN
DELETE
SCREEN
MOVE 0 1
SCREEN
NEWLINE
SCREEN
```
输出:
```c++
#1:
**
#2:
helloworld*
#3:
helloworld
*
#4:
helloworld*
#5:
*helloworld
#6:
*elloworld
#7:
h*elloworld
#8:
*hello*world
#9:
*world
#10:
w*orld
#11:
w
*orld
```

### 样例2

输入：
```c++
17
WRITE helloworld
NEWLINE
WRITE abcde
SCREEN
SELECT 0 0 0 5
SCREEN
COPY
MOVE 1 0
PASTE
SCREEN
SELECT 0 5 1 5
SCREEN
COPY
MOVE 1 10
SCREEN
PASTE
SCREEN
```
输出：
```c++
#1:
helloworld
abcde*
#2:
*hello*world
abcde
#3:
helloworld
hello*abcde
#4:
hello*world
hello*abcde
#5:
helloworld
helloabcde*
#6:
helloworld
helloabcdeworld
hello*
```
### 样例3

输入：
```c++
13
WRITE helloworld
SELECT 0 0 0 5
WRITE replace!
SCREEN
SELECT 0 8 0 13
SCREEN
COPY
SELECT 0 0 0 8
PASTE
SCREEN
SELECT 0 5 0 10
NEWLINE
SCREEN
```
输出：
```c++
#1:
replace!*world
#2:
replace!*world*
#3:
world*world
#4:
world
*
```
### 样例4

见下载文件中4.in和4.out

### 样例5

见下载文件中5.in和5.out

## 要求

    不能修改main.cpp
    下载文件提供了一些已有代码供你参考，但你可以自由选择是否使用。这些文件里还有一些帮助性的说明。 请进一步编写editor.h，也可以增加文件。将除main.cpp以外的文件和makefile打包提交。 注意：下载文件提供了makefile的样本，请仅对objects、requires两个字段进行修改，请勿修改其他部分
    文件下载：下载地址

## 提交格式

请将你的文件打包成一个 zip 格式的压缩包并上传。注意：你的文件应该在压缩包的根目录下，而不是压缩包的一个子文件夹下，换而言之，解压你提交的压缩包后，应该直接得到一系列 cpp 文件、h 文件等代码文件，而不是一个包含它们的文件夹。评测时，OJ会将提供的文件贴入你的目录下进行编译并执行。
