# ITCAST

### 搭建调试环境
* 另见:[behavior/README.md](../behavior/README.md)
* 不同点在于`运行和调试`界面中，如果已经存在调试器(例如:`(lldb)启动(behavior)`)，那么添加新的调试器配置需要通过下拉菜单中`添加配置(itcast)`来实现。
![image](../images/vscode/vscode_create_cpp_debug_settings05.png)
* 此外，该项目还需要为调试器指定动态库的位置,需要修改`environment`字段。
![image](../images/vscode/vscode_create_cpp_debug_settings06.png)
* 选中文件`client.c/server.c`(如果不选中可能导致配置文件中的`${fileDirname}`变量识别错误，进而导致`launch.json/tasks.json`无法执行),按`F5`进入调试时会自动构建可执行程序