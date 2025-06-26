# Blender Development Environment

### Python虚拟环境
参考：[Mac中使用virtualenv和virtualenvwrapper.md](https://github.com/walter201230/Python/blob/master/Article/advanced/Mac中使用virtualenv和virtualenvwrapper.md)
* 安装Python:`brew install python`
* 确认Python:`python3 --version`,`pip3 --version`
* 安装virtualenv:`brew install virtualenv`
* 安装virtualenvwrapper:`brew install virtualenvwrapper`
* 修改`~/.zshrc`(或者`~/.bashrc`)，增加环境变量:
```
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
参考：[Fake Blender Python API module collection: fake-bpy-module](https://github.com/nutti/fake-bpy-module)
* 启动/切换到虚拟环境:`workon blender_development_env`
* 安装fake-bpy-module:`pip install fake-bpy-module-4.2`(与Blender 4.2.10 LTS 版本一致)
* 确认当前虚拟环境安装的模块:`pip list`

### 配置VSCode
以[blender_mmd_tools](https://github.com/MMD-Blender/blender_mmd_tools)插件项目为例
* 克隆:`git clone git@github.com:MMD-Blender/blender_mmd_tools.git`
* 使用**VSCode**打开项目目录，安装Python插件
* 解决**Pylance**语言服务器无法识别`bpy`模块的问题：
  * 打开**VSCode**命名面板:`command + shift + p`
  * 输入:`Python: Select Interpreter`
  * 选择:`Python 3.13.5 (blender_development_env) VirtualEnvWrapper`，确保**VSCode**解释器环境是`blender_development_env`虚拟环境(可能需要重启VSCode)

### 调试Blender
* **VSCode**安装插件**Blender Development**
* 打开**VSCode**命名面板:`command + shift + p`
* 输入:`Blender:Start`
* 点击:`Choose a new Blender Excutable`
* 选择Blender可执行程序并进入调试模式