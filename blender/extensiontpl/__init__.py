import bpy
from . import operators
from . import panel
from . import properties

def register():
    properties.register() # 被依赖的类先注册
    operators.register()
    panel.register()

def unregister():
    panel.unregister()
    operators.unregister()
    properties.unregister() # 被依赖的类最后注销