# properties.py 存放插件自定义属性
# 可以在`Operator`中用`context.scene.my_tool`访问这些属性，也可以在`Panel`中用`layout.prop()`显示它们。
import bpy

class MyProperties(bpy.types.PropertyGroup):
    my_int: bpy.props.IntProperty(
        name="My Integer",
        description="An example integer property",
        default=5,
        min=0,
        max=100
    ) # type: ignore

    my_float: bpy.props.FloatProperty(
        name="My Float",
        description="An example float property",
        default=1.0,
        min=0.0,
        max=10.0
    ) # type: ignore

    my_enum: bpy.props.EnumProperty(
        name="My Enum",
        description="An example enum property",
        items=[
            ('OPT_A', "Option A", "First option"),
            ('OPT_B', "Option B", "Second option"),
            ('OPT_C', "Option C", "Third option"),
        ],
        default='OPT_A'
    ) # type: ignore

    my_bool: bpy.props.BoolProperty(
        name="My Boolean",
        description="An example boolean property",
        default=False,
    ) # type: ignore

    my_string: bpy.props.StringProperty(
        name="My String",
        description="An example string property",
        default="Hello",
        maxlen=1024,
    ) # type: ignore

def register():
    bpy.utils.register_class(MyProperties)
    # `bpy.types.Scene`是`Blender`内置的场景数据类型，`my_tool`是自定义属性名，是挂载在`Scene`类型上的一个属性。
    # 这个属性在`Blender`内部会自动存储到每个场景实例中，能在界面和脚本里用`context.scene.my_tool`访问。
    # 这行代码给`Scene`类型添加一个“指针属性”（PointerProperty），指向一个`PropertyGroup`类型（`MyProperties`）
    bpy.types.Scene.my_tool = bpy.props.PointerProperty(type=MyProperties)

def unregister():
    del bpy.types.Scene.my_tool
    bpy.utils.unregister_class(MyProperties)
