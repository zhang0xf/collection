# C++ Primer 第五版

### 编译所有示例代码
* 切换到“根目录”:`cd booknotes/cppprimer5`
* 构建可执行程序(**Makefile递归**):`make`

### 编译单个章节的示例代码
* 切换到“章节目录”:`cd booknotes/cppprimer5/chapter01`
* 构建可执行程序:`make`

### 搭建调试环境
* 另见: [itcast/README.md](../../itcast/README.md)
* 不同点在于:我们只关心当前示例代码及其可执行程序的调试环境的搭建。(详见`launch.json`与`tasks.json`中的`"${fileDirname}/${fileBasenameNoExtension}"`)

### 调试单个示例代码
* 选中.cpp文件(如：standard_io.cpp)
* `F5`进入调试时会自动生成.cpp对应的可执行程序