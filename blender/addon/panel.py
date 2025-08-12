# panel.py 为插件添加一个用户界面，让你可以通过点击按钮来运行自定义操作
import bpy

class OBJECT_PT_HelloPanel(bpy.types.Panel): # PT = 'Panel Type'
    bl_idname = "OBJECT_PT_hello_panel" # 面板的唯一ID
    bl_label = "Hello Panel Label" # 面板顶部显示的标题
    bl_space_type = 'VIEW_3D' # 面板会出现在3D视图中
    bl_region_type = 'UI' # 面板会出现在右侧标签页[按N呼出]
    bl_category = 'Hello Panel Sidebar' # 右侧标签页的名称

    def draw(self, context):
        layout = self.layout # 一个用于创建UI元素的对象
        layout.operator("object.hello_world") # 添加一个按钮，用于执行`object.hello_world`操作

def register():
    bpy.utils.register_class(OBJECT_PT_HelloPanel)

def unregister():
    bpy.utils.unregister_class(OBJECT_PT_HelloPanel)
