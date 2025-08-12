# Blender Extension Development Template

`Blender 4.0`之后引入了`Extension`插件开发的新标准

### Legacy vs Extension Add-ons

>With the introduction of Extensions in Blender 4.2, the old way of creating add-ons is considered deprecated.

另见：[Legacy vs Extension Add-ons](https://docs.blender.org/manual/en/4.2/advanced/extensions/addons.html#legacy-vs-extension-add-ons)

### Extension插件的目录结构

简化版：
```
extensiontpl/
├── __init__.py
├── blender_manifest.toml ← manifest file
├── operators.py
├── panel.py
├── properties.py
└── README.md
```

实际项目可参考：[blender_mmd_tools](https://github.com/MMD-Blender/blender_mmd_tools) 

### 关于 blender_manifest.toml 文件

这个文件是`Blender 4.0`之后引入的新插件元数据规范（取代了旧的`bl_info`机制的一部分用途）。它会被`Blender Extensions System`和`blender --command extension build/install`命令读取，用来描述：
- 插件的基本信息（名称、版本、作者、描述、分类等）
- 依赖关系（如果有）
- 可选的构建参数（build settings）

详见：[How to Create Extensions](https://docs.blender.org/manual/en/4.2/advanced/extensions/getting_started.html#extensions-getting-started)（对所有`meta-data`有详细描述）


### 打包发布

通过`新建终端`为“插件工作目录”打开一个终端（`vscode`自动为终端激活虚拟环境），然后通过以下命令打包插件：

```shell
cd collection/blender/extensiontpl
/Applications/Blender.app/Contents/MacOS/Blender --command extension build
```

或者只验证清单，不打包插件：

```shell
cd collection/blender/extensiontpl
/Applications/Blender.app/Contents/MacOS/Blender --command extension validate
```

详见：[How to Create Extensions](https://docs.blender.org/manual/en/4.2/advanced/extensions/getting_started.html#extensions-getting-started)

### 搭建开发环境

另见：[搭建Blender开发环境](../../readme/blender_development.md)

