# C++ Primer 第五版

《C++ Primer》（第五版）随书笔记及代码整理

### 编译代码
编译所有示例代码：
* `cd collection/booknotes/cppprimer5`
* `make`

编译单个章节示例代码
* `cd collection/booknotes/cppprimer5/chapter01`
* `make`

### 运行项目
略

### 搭建调试环境
参考：[创建C/C++调试器](../../behavior/README.md#搭建调试环境)

注意：对于某一示例的代码，我们需要为其构建可执行程序并修改调试器中的`"program"`字段。为此，可以使用`"${fileDirname}/${fileBasenameNoExtension}"`来处理所有示例。【详见：`launch.json`与`tasks.json`】

注意：调试某一示例代码时，必须先选中`main()`函数所在文件（例如：`chapter01/standard_io.cpp`）