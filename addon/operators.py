import bpy

class OBJECT_OT_HelloWorld(bpy.types.Operator): # OT: 'Operator Type'
    bl_idname = "object.hello_world" # 操作的唯一标识符
    bl_label = "Say Hello" # UI中显示的名称
    
    def execute(self, context): 
        self.report({'INFO'}, "Hello from plugin!")
        print("Hello World in Console")
        return {'FINISHED'}

class OBJECT_OT_PrintProperties(bpy.types.Operator):
    bl_idname = "object.print_properties"
    bl_label = "Print Properties"
    
    def execute(self, context):
        props = context.scene.my_tool
        print(f"Integer: {props.my_int}")
        print(f"Float: {props.my_float}")
        print(f"Enum: {props.my_enum}")
        print(f"Boolean: {props.my_bool}")
        print(f"String: {props.my_string}")
        self.report({'INFO'}, f"Int={props.my_int}, Float={props.my_float}, Enum={props.my_enum}, Bool={props.my_bool}, String='{props.my_string}'")
        return {'FINISHED'}

def register():
    bpy.utils.register_class(OBJECT_OT_HelloWorld)
    bpy.utils.register_class(OBJECT_OT_PrintProperties)

def unregister():
    bpy.utils.unregister_class(OBJECT_OT_PrintProperties) # 逆序注销
    bpy.utils.unregister_class(OBJECT_OT_HelloWorld)