bl_info = {
    "name": "Addon Template", # 插件的显示名称，在'Edit > Preferences > Add-ons'的插件列表中会显示这个名字
    "blender": (2, 80, 0), # 插件支持的最低'Blender版本'
    "category": "Object", # 插件分类标签，用于组织插件在列表中的位置（注意不是'UI面板'的位置）
    "version": (1, 0), # 插件的版本号，用于插件更新管理
    "author": "zhang0xf", # 插件的作者名字
    "description": "一个插件开发的模版", # 插件简介，会显示在'Add-ons'面板插件项的下方，帮助用户了解插件用途
    "warning": "该插件仅用于学习和测试", # 插件在当前版本下是否有已知问题或不稳定性
    "doc_url": "https://github.com/zhang0xf/collection/blender/myaddon/README.md" # 插件的文档链接
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
