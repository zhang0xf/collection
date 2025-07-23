# 第一章 - 开始

### 1.1 编写一个简单的程序
> 一个函数的定义包含四部分：返回类型（return type）、函数名（function name）、一个括号包围的形参列表（parameter list，允许为空）以及函数体（function body）。虽然main函数在某种程度上比较特殊，但其定义与其他函数是一样的。

一个简单的程序：
```cpp
int main()
{
    return 0;
}
```

### 1.2 初识输入输出
> 本书中的很多示例都使用了iostream库。iostream库包含两个基础类型istream和ostream，分别表示输入流和输出流。一个流就是一个字符序列，是从IO设备读出或写入IO设备的。术语“流”（stream）想要表达的是，随着时间的推移，字符是顺序生成或消耗的。

> 标准库定义了4个IO对象。为了处理输入，我们使用一个名为cin（发音为see-in）的istream类型的对象。这个对象也被称为标准输入（standard input）。对于输出，我们使用一个名为cout（发音为see-out）的ostream类型的对象。此对象也被称为标准输出（standard output）。标准库还定义了其他两个ostream对象，名为cerr和clog（发音分别为see-err和see-log）。我们通常用cerr来输出警告和错误消息，因此它也被称为标准错误（standard error）。而clog用来输出程序运行时的一般性信息。

一个使用IO库的程序：
```cpp
#include <iostream>

int main()
{
    std::cout << "enter two numbers" << std::endl;
    int v1 = 0, v2 = 1;
    std::cin >> v1 >> v2;
    std::cout << "the sum of " << v1 << "and " << v2 << "is " << v1 + v2 << std::endl;
    return 0;
}
```

解析语句:

```cpp
    std::cout << "enter two numbers" << std::endl;
```

> <<运算符接受两个运算对象：左侧的运算对象必须是一个ostream对象，右侧的运算对象是要打印的值。此运算符将给定的值写到给定的ostream对象中。输出运算符的计算结果就是其左侧运算对象。

> 我们的输出语句使用了两次<<运算符。因为此运算符返回其左侧的运算对象，因此第一个运算符的结果成为了第二个运算符的左侧运算对象。

> 第二个运算符打印endl，这是一个被称为操纵符（manipulator）的特殊值。写入endl的效果是结束当前行，并将与设备关联的缓冲区（buffer）中的内容刷到设备中。

>前缀std：：指出名字cout和endl是定义在名为std的命名空间（namespace）中的。命名空间可以帮助我们避免不经意的名字定义冲突，以及使用库中相同名字导致的冲突。

**WARNING**：
> 程序员常常在调试时添加打印语句。这类语句应该保证“一直”刷新流。否则，如果程序崩溃，输出可能还留在缓冲区中，从而导致关于程序崩溃位置的错误推断。

解析语句：
```cpp
    std::cin >> v1 >> v2;
```