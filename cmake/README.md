# cmake
cmake寻找顶层目录下的CMakeLists.txt以执行编译，并生成Makefile.

## 自定义编译选项
CMake允许为项目增加编译选项，从而根据用户的环境和需求选择最合适的编译方案。例如：可以将mymath设置为可选库。如果选项为ON ，就使用该库定义的数学函数，否则就使用标准库中的数学函数库。

## 安装和测试
CMake可以指定安装规则及添加测试。这两个功能分别通过产生Makefile后使用make install和make test来实现。在以前的GNU Makefile里，你可能需要为此编写install和test两个伪目标和相应的规则，但在CMake里，这样的工作只需要简单的几条命令。
1. 使用Install命令实现安装。
2. main和libmymath.a会被复制到 **/usr/local/bin**
3. mymath.h和config.h会被复制到 **/usr/local/include**
4. /usr/local是安装默认的根目录，使用变量**CMAKE_INSTALL_PREFIX**来重新指定根目录。

## 支持gdb
让CMake支持gdb，只需要指定Debug模式下开启-g选项。

## 添加环境检查
有时候可能要对系统环境做点检查，例如要使用一个平台相关的特性的时候。在这个例子中，我们检查系统是否自带pow函数。如果有pow函数就使用它；否则使用我们定义的power函数。

## 生成安装包
配置生成各种平台上的安装包，包括二进制安装包和源码安装包。为了完成这个任务，我们需要用到CPack，它同样也是由CMake提供的一个工具，专门用于打包。
1. 导入InstallRequiredSystemLibraries模块，以便之后导入CPack模块；
2. 设置一些CPack相关变量，包括版权信息和版本信息，其中版本信息使用了上一案例定义的版本号；
3. 导入CPack模块。

# Reference
* [Cmake-Documention](https://cmake.org/cmake/help/cmake2.4docs.html)
* [Cmake-Tutorial](https://cmake.org/cmake-tutorial/)
* [Cmake-Community-Wiki](https://gitlab.kitware.com/cmake/community/wikis/home)
* [CMake-Bug-Tracker](https://gitlab.kitware.com/cmake/cmake/issues)
* [Cmake-FAQ](https://gitlab.kitware.com/cmake/community/wikis/FAQ)
* [Cmake-Famous-Projects](https://gitlab.kitware.com/cmake/community/wikis/doc/cmake/Projects)
* [https://github.com/wzpan/cmake-demo](https://github.com/wzpan/cmake-demo)