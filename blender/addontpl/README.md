# Blender Addon Development Template

这是一个`blender`插件开发的示例模版，使用“模块结构”:
```
addontpl/
├── __init__.py         ← 插件入口，必须有
├── operators.py        ← 自定义操作（功能代码）
├── panel.py            ← UI面板（按钮、滑条等）
├── utils.py            ← 可选工具模块（辅助函数）
└── README.md           ← 插件说明文档（非必需）
```
最终只需要将`addontpl/`目录压缩成`ZIP`文件即可用于安装：
```shell
zip -r addontpl.zip addontpl
```

### Legacy vs Extension Add-ons

>With the introduction of Extensions in Blender 4.2, the old way of creating add-ons is considered deprecated.

另见：[Legacy vs Extension Add-ons](https://docs.blender.org/manual/en/4.2/advanced/extensions/addons.html#legacy-vs-extension-add-ons)

Extension插件的目录结构：
```
addontpl/
├── blender_addon.yaml
├── addontpl/
│   ├── __init__.py
│   ├── operators.py
│   └── panel.py
└── requirements.txt
```

### 搭建开发环境

另见：[Blender开发环境](../../readme/blender_development.md)

### Operator的含义
在`Blender`中，**Operator** 是所有功能的核心，比如：
- 添加一个立方体：`bpy.ops.mesh.primitive_cube_add()`
- 移动物体：`bpy.ops.transform.translate()`
- 自定义按钮点击逻辑：`bpy.ops.object.hello_world()`


