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
    bpy.types.Scene.my_tool = bpy.props.PointerProperty(type=MyProperties)

def unregister():
    del bpy.types.Scene.my_tool
    bpy.utils.unregister_class(MyProperties)
