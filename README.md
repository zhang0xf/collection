# Collections

### 搭建多根工作区
* 在项目根目录使用`将工作区另存为...`创建工作区文件:`collection.code-workspace`
* 使用`将文件夹添加到工作区...`将根目录添加到工作区,解决`工作区视图`与`Git`冲突的问题。使得根目录下那些非`文件夹`类型的文件(如:README.md)纳入到Git管理
* 使用`将文件夹添加到工作区...`将某一独立的项目(如:`behavior`是一个c++编写的行为树案例;`itcast`是一个c编写的网络加密传输案例)添加到工作区,并为其搭建独立的开发调试环境(另见具体项目的README,如:[behavior/README.md](./behavior/README.md))