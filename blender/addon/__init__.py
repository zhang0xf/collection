bl_info = {
    "name": "Addon Template", # 插件的显示名称
    "blender": (2, 80, 0), # 插件支持的最低版本
    "category": "Object", # 插件的分类标签
    "version": (1, 0), # 插件的版本号
    "author": "zhang0xf", # 插件的作者名字
    "description": "一个插件开发的模版", # 插件的简介
    "warning": "该插件仅用于学习和测试", # 插件在当前版本下是否有已知问题或不稳定性
    "doc_url": "https://github.com/zhang0xf/collection/blender/addon/README.md" # 插件的文档链接
}

import bpy
from . import operators
from . import panel

def register():
    operators.register()
    panel.register()

def unregister():
    panel.unregister()
    operators.unregister()
