# Blender Development Environment

### Python虚拟环境
参考：[Mac中使用virtualenv和virtualenvwrapper.md](https://github.com/walter201230/Python/blob/master/Article/advanced/Mac中使用virtualenv和virtualenvwrapper.md)
* 安装Python:`brew install python`
* 确认Python:`python3 --version`,`pip3 --version`
* 安装virtualenv:`brew install virtualenv`
* 安装virtualenvwrapper:`brew install virtualenvwrapper`
* 修改`~/.zshrc`(或者`~/.bashrc`)，增加环境变量:
```shell
# python virtualenvwrapper
export WORKON_HOME='~/.virtualenvs'
export VIRTUALENVWRAPPER_PYTHON=/opt/homebrew/bin/python3
source /opt/homebrew/bin/virtualenvwrapper.sh
```
* 重新加载终端配置:`source ~/.zshrc`
* 创建虚拟环境:`mkvirtualenv blender_development_env`
* 列出虚拟环境列表:`workon`
* 启动/切换虚拟环境:`workon blender_development_env`

### 为虚拟环境(blender_development_env)安装Blender开发依赖
* 启动/切换到虚拟环境:`workon blender_development_env`
* 安装fake-bpy-module:`pip install fake-bpy-module-4.2`([fake-bpy-module](https://github.com/nutti/fake-bpy-module))
* 确认当前虚拟环境安装的模块:`pip list`

### VS Code 配置
* 打开项目目录，为编辑器安装Python插件
* 解决`Pylance`语言服务器无法识别`bpy`模块的问题：
  * <del>呼出命名面板:`command + shift + p`</del>
  * <del>输入:`Python: Select Interpreter`</del>
  * <del>选择:`Python 3.13.5 (blender_development_env) VirtualEnvWrapper`</del>

* 注意：由于`VS Code`更新到`版本: 1.102.3 (Universal)`。新增了`Python环境管理界面`，它将 Python 环境的管理从以前的纯路径识别转向更加结构化的方式，比如强调 venv, conda, poetry, pyenv 等 “官方支持的环境管理器”，而对 virtualenvwrapper（即 mkvirtualenv）创建的环境支持 变得不明显，因此不能自动识别 ~/.virtualenvs 中的虚拟环境。在解释器选择界面（Command Palette → Python: Select Interpreter）里看不到它们。所以需要从`Python环境管理界面`来为项目创建虚拟环境。这将在"根目录"下创建`.venv`文件夹，`新建终端`也会自动激活对应的虚拟环境。

### 调试插件代码
* 安装扩展: **Blender Development**
* 呼出命名面板:`command + shift + p`
* 输入:`Blender:Start`
* 选择:`Choose a new Blender Excutable`

### 代码的热重载
* 在`Blender`中`取消激活 -> 激活`插件即可重载插件代码