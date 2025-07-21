# WebServer

### Makefile Build
* `make`: 生成所有可执行程序
* `make clean`: 删除所有可执行程序

### 搭建调试环境
* 创建`launch package(webserver)`调试器。另见: [sheetparser/README.md](../sheetparser/README.md)
* 注意: `launch.json`配置的`program`字段需要指向`main.go`所在的目录或直接指向`main.go`,而不是编译之后的二进制文件(与`c/c++`的调试配置是不同的)
* 注意: `launch.json`配置时使用`${workspaceFolder}`变量更为方便
* 此外，该项目不需要`tasks.json`配置