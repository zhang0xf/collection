# Blender Addon Development Template

这是一个`Blender Addon`插件开发的模版

### Addon插件的目录结构

简化版：
```
addontpl/
├── __init__.py         ← 插件入口，必须有
├── operators.py        ← 自定义操作（功能代码）
├── panel.py            ← UI面板（按钮、滑条等）
├── utils.py            ← 可选工具模块（辅助函数）
└── README.md           ← 插件说明文档（非必需）
```

### 打包发布

```shell
cd collection/blender
zip -r addontpl.zip addontpl
```

### 搭建开发环境

另见：[搭建Blender开发环境](../../readme/blender_development.md)