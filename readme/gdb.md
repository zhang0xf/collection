# gdb
GDB的高频操作

## 生成调试信息
在编译时，使用-g参数把调试信息加到可执行文件中：
* `gcc -g hello.c -o hello`
* `g++ -g hello.cpp -o hello`

## 调试
* `gdb program`:启动gdb
* `set args 10 20 30 40 50`:设置参数
* `show args`:查看参数设置
* `run`:启动程序
* `pwd`:查看当前工作目录
* `b 10`:在程序第10行设置断点
* `b func`:在函数func入口处设置断点
* `break test.c:20`:在源文件test.c的20行处停住
* `break test.c:func`:在源文件test.c的func函数的入口处停住
* `break class::func`在类class的func函数的入口处停住
* `break namespace::class::func`:在命名空间namespace的类class的func函数的入口处停住
* `b test.c:8 if intValue == 5`:设置条件断点，使用if关键词+断点条件
* `info b`:查询断点信息
* `d [range...]`:删除断点(若不指定range，表示删除所有断点)
* `dis [range...]`:失效断点(若不指定range，表示失效所有断点，并不会删除断点)
* `ena [range...]`:激活断点(若不指定range，表示激活所有断点)
* `r`:运行程序
* `n`:单步跟踪,不进入函数内部
* `s`:单步跟踪,进入函数内部
* `finish`:退出进入的函数
* `u`:可以运行程序直到退出当前循环体
* `c`:继续运行程序
* `p val`:手动打印变量值
* `display val`:设置变量自动显示
* `info display`:查看display设置信息
* `undisplay num`隐藏num(info display时显示的编号)
* `delete display dnums…`:删除自动显示,dnums为编号,以空格分隔,支持范围删除(2-5)
* `disable display dnums…`:失效自动显示,dnums为编号,不会删除自动显示设置
* `enable display dnums…`:激活自动显示
* `ptype width`:查看变量width的类型
* `set var width=47`:改变变量值
* `list linenum`:显示源码，默认打印10行(上下文各5行)
* `list function`:显示function函数的源码，默认打印10行(上下文各是2行、8行)
* `list`:显示当前行后面的源程序
* `list -`:显示当前行前面的源程序
* `set listsize count`:设置显示源码的行数
* `show listsize`:查看当前listsize设置
* `info threads`:显示当前可调试的所有线程，会显示线程ID
* `thread ID `:切换到指定ID的线程
* `break file.c:123 thread all`:在所有线程的某行设置断点
* `thread apply [thread-id-list] [all] args`:在一系列线程上执行命令
* `set print thread-events`:控制打印线程启动或结束时的信息
* `set scheduler-locking off|on|step`:使用step或是continue调试时，其他线程会并行执行，需锁定线程。off：不锁定任何线程，也就是所有的线程都执行，这是默认值。on：只有当前被调试的线程能够执行。step：阻止其他线程在当前线程单步调试时，抢占当前线程。只有当next、continue、util以及finish的时候，其他线程才会获得重新运行的机会。

## .core文件
* `ulimit -c`:查看是否可以生成.core文件
* `ulimit -c unlimited`:允许生成.core文件且不限制大小
* `gdb [exec file] [core file]`:GDB调试.core文件：`gdb ./main main.core`
* `where`:查找段错误位置