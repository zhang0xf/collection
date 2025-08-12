# panel.py 为你的插件添加一个用户界面，让你可以通过点击按钮来运行自定义操作（Operator）
import bpy

class OBJECT_PT_HelloPanel(bpy.types.Panel): # PT = 'Panel Type'
    bl_label = "Hello Panel Label" # 面板顶部显示的标题
    bl_idname = "OBJECT_PT_hello_panel" # 面板的唯一ID
    bl_space_type = 'VIEW_3D' # 表示该面板会出现在'3D视图'中
    bl_region_type = 'UI' # 表示该面板会出现在右侧标签页（按N呼出）
    bl_category = 'Hello Panel Sidebar' # 标签页名字

    # UI绘制函数
    def draw(self, context):
        layout = self.layout # 一个用于创建UI元素的对象
        props = context.scene.my_tool

        # 显示属性输入
        layout.prop(props, "my_int")
        layout.prop(props, "my_float")
        layout.prop(props, "my_enum")
        layout.prop(props, "my_bool")
        layout.prop(props, "my_string")

        # 按钮区
        layout.operator("object.hello_world") # 添加一个按钮，用于执行'object.hello_world'操作
        layout.operator("object.print_properties")

def register():
    bpy.utils.register_class(OBJECT_PT_HelloPanel)

def unregister():
    bpy.utils.unregister_class(OBJECT_PT_HelloPanel)
