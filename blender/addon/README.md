# <del>Blender Addon Development Template</del>【弃用】

<del>这是一个`Blender Addon`插件开发的模版</del>【请按新的插件标准来构建项目，另见：[Blender Extension Development Template](../extensiontpl/README.md)】

### Addon插件的目录结构

简化版：
```
addon/
├── __init__.py         ← 插件入口，必须有
├── operators.py        ← 自定义操作（功能代码）
├── panel.py            ← UI面板（按钮、滑条等）
├── utils.py            ← 可选工具模块（辅助函数）
└── README.md           ← 插件说明文档（非必需）
```

### 打包发布

```shell
cd collection/blender
zip -r addon.zip addon
```

### 搭建开发环境

另见：[搭建Blender开发环境](../../readme/blender_development.md)