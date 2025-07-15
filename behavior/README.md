# Behavior Tree
Reference: [GameAI-BehaviorTree](https://github.com/zzwzfy/GameAI-BehaviorTree)

### 搭建调试环境
* 选中`main.cpp`(如果不选中cpp文件,vscode可能不能识别当前子文件夹为c++项目,就不能正确配置c++工具链或不能激活c++插件环境,那么在调试配置菜单中就不会显示gdb/lldb相关选项),进入`运行和调试`页签,点击`创建launch.json文件`
![image](../images/vscode/vscode_create_cpp_debug_settings01.png)
* 选择`behavior`工作区,并为该工作区选择`c/c++ lldb(启动)`调试器
![image](../images/vscode/vscode_create_cpp_debug_settings02.png)
* 在生成的`launch.json`文件中修改`program`字段为相应的可执行程序路径
![image](../images/vscode/vscode_create_cpp_debug_settings03.png)
![image](../images/vscode/vscode_create_cpp_debug_settings04.png)
* 在终端执行`make`,编译并生成可执行程序`main`
* 设置断点,`F5`进入调试