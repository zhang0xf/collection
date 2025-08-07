# Blender Development Environment

### <del>Python虚拟环境</del>【弃用】
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

* 注意：由于`VS Code`更新到`版本: 1.102.3 (Universal)`。新增了`Python环境管理界面`，它将 Python 环境的管理从以前的纯路径识别转向更加结构化的方式，比如强调 venv, conda, poetry, pyenv 等 “官方支持的环境管理器”，而对 virtualenvwrapper（即 mkvirtualenv）创建的环境支持 变得不明显，因此不能自动识别 ~/.virtualenvs 中的虚拟环境。在解释器选择界面（Command Palette → Python: Select Interpreter）里看不到它们。因此需要从`Python环境管理界面`来为插件项目创建虚拟环境，这将在项目的"根目录"下创建`.venv`文件夹。`新建终端`会自动激活对应的虚拟环境，在该虚拟环境下安装`blender`插件开发所需的依赖:`pip install fake-bpy-module-4.2`

### 调试插件代码
* 安装扩展： **Blender Development**
* 呼出命名面板：`command + shift + p`
* 输入：`Blender: Start`
* 选择：`Choose a new Blender Excutable`

### 代码的热重载
* 呼出命名面板:`command + shift + p`
* 输入：`Blender: Reload Addons`
* 在编辑器的`调试控制台`或`终端`确认日志输出：`Sending: {'type': 'addonUpdated'}`
* 返回`Blender`确认热重载成功

### 插件开发和日常工作隔离

How can I separate development environment from my daily work?

By default, Blender started from VS Code uses your global Blender settings

To prevent any accidental changes to your daily setup, change environment var in VS Code setting `"blender.environmentVariables"`
```json
"blender.environmentVariables": {
			"BLENDER_USER_RESOURCES": "./blender_vscode_development" // changes folder for addons, extensions, modules, config
		},
```

注意：如果使用“多根工作区”（[Multi-root Workspace](https://code.visualstudio.com/docs/editing/workspaces/multi-root-workspaces)），那么`"blender.environmentVariables"`字段应该写入工作区文件`collection.code-workspace`，而非子项目的`myaddon/.vscode/settings.json`，否则不会生效。

### 安全退出

当开发告一段落后，若直接关闭`Blender.app`会导致插件无法执行`unregister()`，进而无法清理尚在开发中的插件。可以使用编辑器扩展（`Blender Development`）提供的`Blender: Stop`终止插件的开发和调试（实际测试貌似没有用）：
* 呼出命名面板:`command + shift + p`
* 输入：`Blender: Stop`

注意：如果配置了[插件开发和日常工作隔离](#插件开发和日常工作隔离)，那么会创建一个用于插件开发的隔离环境（`colletion/blender_vscode_development`），即配置一份新的`Userpref`，与日常工作的`Userpref`隔离开来。这样，即使未能正确清理尚在开发中的插件也没关系，因为开发用隔离环境不会影响到日常工作!