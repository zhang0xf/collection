import bpy

class OBJECT_PT_HelloPanel(bpy.types.Panel): # PT: 'Panel Type'
    bl_label = "Hello Panel Label" # 面板顶部标题
    bl_idname = "OBJECT_PT_hello_panel" # 面板唯一标识符
    bl_space_type = 'VIEW_3D' # 面板在3D视图中
    bl_region_type = 'UI' # 面板在右侧标签页[按N呼出]
    bl_category = 'Hello Panel Sidebar' # 面板标签页的名称

    def draw(self, context):
        layout = self.layout
        props = context.scene.my_tool

        layout.prop(props, "my_int")
        layout.prop(props, "my_float")
        layout.prop(props, "my_enum")
        layout.prop(props, "my_bool")
        layout.prop(props, "my_string")

        layout.operator("object.hello_world")
        layout.operator("object.print_properties")

def register():
    bpy.utils.register_class(OBJECT_PT_HelloPanel)

def unregister():
    bpy.utils.unregister_class(OBJECT_PT_HelloPanel)
