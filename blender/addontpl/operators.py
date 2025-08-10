# operators.py 是集中写所有自定义操作行为的地方，每个操作都是一个继承自 bpy.types.Operator 的类
import bpy

class OBJECT_OT_HelloWorld(bpy.types.Operator): # OT = 'Operator Type'
    bl_idname = "object.hello_world" # 操作的唯一标识符
    bl_label = "Say Hello" # 这是UI中显示的名称（在按钮上就会显示'Say Hello'）
    
    # 插件操作的核心方法
    def execute(self, context): 
        self.report({'INFO'}, "Hello from plugin!") # 在界面状态栏提示'Hello from plugin!'
        print("Hello World in Console") # 在控制台输出'Hello World in Console'
        return {'FINISHED'} # 返回 {'FINISHED'} 表示操作完成

def register():
    bpy.utils.register_class(OBJECT_OT_HelloWorld)

def unregister():
    bpy.utils.unregister_class(OBJECT_OT_HelloWorld)
