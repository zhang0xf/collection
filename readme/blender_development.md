# Blender Development Environment

### ~~Python虚拟环境~~【弃用】
---
~~参考：[Mac中使用virtualenv和virtualenvwrapper.md](https://github.com/walter201230/Python/blob/master/Article/advanced/Mac中使用virtualenv和virtualenvwrapper.md)~~
* ~~安装Python:`brew install python`~~
* ~~确认Python:`python3 --version`,`pip3 --version`~~
* ~~安装virtualenv:`brew install virtualenv`~~
* ~~安装virtualenvwrapper:`brew install virtualenvwrapper`~~
* ~~修改`~/.zshrc`(或者`~/.bashrc`)，增加环境变量:~~
<div style="margin-left: 2em">

```shell
# python virtualenvwrapper
export WORKON_HOME='~/.virtualenvs'
export VIRTUALENVWRAPPER_PYTHON=/opt/homebrew/bin/python3
source /opt/homebrew/bin/virtualenvwrapper.sh
```
</div>

* ~~重新加载终端配置:`source ~/.zshrc`~~
* ~~创建虚拟环境:`mkvirtualenv blender_development_env`~~
* ~~列出虚拟环境列表:`workon`~~
* ~~启动/切换虚拟环境:`workon blender_development_env`~~

### ~~为虚拟环境安装开发依赖~~【弃用】
---
* ~~启动/切换到虚拟环境:`workon blender_development_env`~~
* ~~安装fake-bpy-module:`pip install fake-bpy-module-4.2`([fake-bpy-module](https://github.com/nutti/fake-bpy-module))~~
* ~~确认当前虚拟环境安装的模块:`pip list`~~

### ~~为`VSCode`选择`Python`解释器~~【弃用】
---
* ~~呼出命名面板:`command + shift + p`~~
* ~~搜索:`Python: Select Interpreter`~~
* ~~选择:`Python 3.13.5 (blender_development_env)`~~

### 在`VSCode`中配置
---
参考：[创建python虚拟环境](../readme/vscode.md#创建python虚拟环境)
* 安装[fake-bpy-module](https://github.com/nutti/fake-bpy-module)依赖包：`pip install fake-bpy-module-4.2`
* 确认安装包信息：`pip list`

### 插件开发和日常工作隔离【重要】
---
安装`VSCode`扩展：**Blender Development**

>How can I separate development environment from my daily work?

>By default, Blender started from VS Code uses your global Blender settings

>To prevent any accidental changes to your daily setup, change environment var in VS Code setting `"blender.environmentVariables"`

```json
"blender.environmentVariables": {
  "BLENDER_USER_RESOURCES": "./blender_vscode_development" // changes folder for addons, extensions, modules, config
},
```

注意：如果使用“多根工作区”（[Multi-Root Workspace](https://code.visualstudio.com/docs/editing/workspaces/multi-root-workspaces)），那么`"blender.environmentVariables"`字段应该配置在工作区文件`collection.code-workspace`，而非`addon/.vscode/settings.json`，否则不会生效。

### 调试插件代码
---
安装`VSCode`扩展：**Blender Development**
* 呼出命名面板：`command + shift + p`
* 搜索：`Blender: Start`
* 选择：`Choose a new Blender Excutable`

### 代码的热重载
---
安装`VSCode`扩展：**Blender Development**
* 呼出命名面板:`command + shift + p`
* 搜索：`Blender: Reload Addons`
* ~~在编辑器的`调试控制台`或`终端`确认日志输出：`Sending: {'type': 'addonUpdated'}`~~【过时】
* 返回`Blender`确认热重载成功

### 安全退出开发
---
安装`VSCode`扩展：**Blender Development**
* 呼出命名面板:`command + shift + p`
* 搜索：`Blender: Stop`

注意：插件提供的`Blender: Stop`命令并不完善。应当配置[插件开发和日常工作隔离](#插件开发和日常工作隔离重要)，创建一个用于插件开发的隔离环境（`./blender_vscode_development`），即使未能正确清理尚在开发中的插件也没关系，因为开发用隔离环境不会影响到日常工作!

已知问题：若无法启动调试，可删除`./blender_vscode_development`后重试

### 打包发布
---
在`VSCode`中为工作区`新建终端`（会自动激活对应的虚拟环境）
* 打包插件：
<div style="margin-left: 2em">

```shell
cd collection/addon
/Applications/Blender.app/Contents/MacOS/Blender --command extension build
```
</div>

* 只验证清单，不打包插件：
<div style="margin-left: 2em">

```shell
cd collection/addon
/Applications/Blender.app/Contents/MacOS/Blender --command extension validate
```
</div>
