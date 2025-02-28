# blender偏好设置
* 视图切换-自动深度(避免缩放视图很慢):
![image](../images/blender/Navigation_Orbit_Depth.png)
* 右键选择:
![image](../images/blender/Ketmap_Select_With_Mouse_Button.png)
* 空格键搜索:
![image](../images/blender/Keymap_Spacebar_Action.png)
* 鼠标中键视图检视:
![image](../images/blender/Keymap_Middle_Mouse_Action.png)

# blender资产库
* 创建blender资产库:
![image](../images/blender/File_Paths_Asset_Library.png)

# blender快捷键

* `shift + 鼠标中键`:平移视角
* `shift + s`:游标吸附【菜单】
* `shift + c`:游标至世界原点

### 选择
* `a`:全选所有对象
* `control + 鼠标左键`:选择/取消选择(若选择对象非活动对象，则将对象置为活动对象)
* `[大纲视图] shift + 鼠标左键`:大纲视图内范围选择
* `[编辑模式(边)] select -> select loops -> select loop Inner-region`:选择循环边内部(建议加入Quick菜单)
* `shift + 右键`:选择多个对象
* `shift + cmd + 右键`:取消选择某个对象

### 对象
* `shift + a`:添加对象【菜单】
* `shift + d`:复制对象
* `x -> delete`:删除对象
* `/`:聚焦选中对象/取消聚焦
* `cmd + j`:合并多个对象
* `w`:上下文菜单
* `shift + z`:切换到线框模式
* `h`:隐藏(物体/点/线/面)
* `option + h`:恢复所有隐藏(物体/点/线/面)
* `control + l -> material`:连接(复用)材质

### 变换
* `g`:移动
* `g + x`:x轴移动
* `g + y`:y轴(world)移动
* `g + y + y`:y轴(local)移动
* `g + z`:z轴移动
* `g + shift + y`:沿着xz平面移动
* `[物体模式] option + g`:重置位置
* `s`:缩放
* `s + x`:x轴缩放
* `s + y`:y轴缩放
* `s + z`:z轴缩放
* `option + s`:重置缩放
* `[编辑模式] option + s`:沿法线方向缩放
* `r`:旋转
* `r + x`:x轴旋转
* `r + y`:y轴旋转
* `r + z`:z轴旋转
* `option + r`:重置旋转
* `cmd + a -> 全部变换`:应用所有变换

### 编辑(点/线/面)
* `TAB`:进入编辑模式
* `1`:点选择模式(非数字键盘)
* `2`:边选择模式
* `3`:面选择模式
* `e`:挤出(点/线/面)
* `e + x`:沿x轴方向挤出
* `e + y`:沿y轴方向挤出
* `e + z`:沿z轴方向挤出
* `option + e -> 沿法线方向挤出`:多个面分别沿其法线方向挤出
* `control + 鼠标左键`:挤出到鼠标位置(点/线/面)
* `control + r`:环切
* `control + r + 滚轮Up`:环切并增加切割次数
* `control + r + 滚轮Down`:环切并减少切割次数
* `control + b`:倒角
* `control + b + 滚轮Up`:倒角并增加段数
* `control + b + 滚轮Down`:倒角并减少段数
* `option + 鼠标右键`:选择循环边
* `右键 + control(hold) + 右键`:起点至终点最佳路径(点/线/面)
* `control + i`:反选
* `[编辑模式(面)] c`:刷选
* `[编辑模式(面)] c + 滚轮Up`:刷选并增加刷子直径
* `[编辑模式(面)] c + 滚轮Down`:刷选并减少刷子直径
* `v`:断离(点/线)
* `control + l`:选择所有相邻元素
* `i`:内插面(面)
* `k`:小刀(自定义拓扑结构)
* `Search(空格键) -> 桥接循环边`:桥接两条循环边(需同一个对象)
* `cmd + e -> 桥接循环边`:桥接两条循环边(需同一个对象, cmd + j可以合并对象)
* `g + g`:滑移边线(点/线/面)
* `m -> 到中心`:合并(点/线/面)
* `m -> 按距离`:合并(点/线/面)(可以用来去除重复点)
* `p -> 选中项`:分离(点/线/面)
* `Search(空格键) -> Grid Fill`:网格填充(边需是偶数)
* `cmd + f -> 栅格填充`:网格填充(边需是偶数)
* `f`:快速网格填充
* `shift + n`:重新计算法线方向
* `option + n -> 翻转`:翻转法线方向

### 骨骼
* `control + p -> 保持偏移量`:设置父子关系(骨骼)
* `option + p -> Clear Parent`:清除父子关系(骨骼)

### 动画
* `k -> location & rotation`:插入选中骨骼的关键帧
* `shift + space`:播放动画
* `shift + <-`:跳转到起始帧
* `shift + ->`:跳转到结束帧

### 曲线
* `[曲线编辑模式] e`:挤出新的曲线控制点（control point）
* `[曲线编辑模式] x`:删除曲线控制点（control point）
* `[曲线编辑模式] option + s`:缩放曲线控制点（control point）的半径（radius）
* `[曲线编辑模式] control + t`:缩放曲线控制点（control point）的倾斜角（tilt）

# blender实用技巧
* 展UV时，在`UV Editing`操作界面下，打开`UV Sync Selection`选项

# Unity优化建议
* Optimize your geometry: don’t use any more triangles than necessary, and try to keep the number of UV mapping seams and hard edges (doubled-up vertices) as low as possible. For more information, see [Creating models for optimal performance](https://docs.unity3d.com/2022.3/Documentation/Manual/ModelingOptimizedCharacters.html).
* Use the Level Of Detail system.