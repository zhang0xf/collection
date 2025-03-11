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
* `control + l`:全选与当前骨骼相连的骨骼链
* `[姿态模式] Pose -> Constraints -> Copy Constraints to select bones`:拷贝活动骨骼的'Constraints'到选择的骨骼

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

# blender实用技巧、注意事项、问题及解决方案
### UV同步
* 展UV时，在`UV Editing`操作界面下，打开`UV Sync Selection`选项

### UV与游戏表现和性能的相关性
* 展UV时，叠放UV布局(例如对称的左右手)可以充分利用Texture有限的空间，减少Texture数量有助于提升性能。但是会限制艺术表现(例如左右手可能会要求不同的贴花,则不适合叠放UV)。
* 展UV时，游戏中细节多、屏幕占比大的UV孤岛需要尽可能放大,相反被遮挡、细节少、屏幕占比小的UV孤岛需要尽可能缩小。

### 建模、绑定和动画分文件(多人协作开发)
* 将需要共享的对象整理到一个集合，使用`Link`关联文件；使用`Library Overide -> Make -> Select & Content`在关联文件的基础上作修改；使用`Library Overide -> Reset -> Select & Content`放弃修改或更新关联文件；对于关联文件无法支持的修改(例如权重绘制)，使用`ID Data -> Make Local`本地化(会取消关联)；另见:[鸽子老师的Blender教程 第一节](https://www.bilibili.com/video/BV1Md4y1g7qZ/?spm_id_from=333.1387.favlist.content.click)

### UV形变的镜像同步
* 问题描述:镜像对称的对象,更改某一边UV,希望另一边UV镜像同步
![image](../images/blender/UV_Mirror_Sync.png)
* 解决方案:删除另一边UV,并添加镜像修改器,勾选UV沿轴向对称,最后应用修改器
![image](../images/blender/UV_Mirror_Sync_Solution.png)

### UV打直
* 问题描述:UV弯曲占用较多Texture空间,打直以更好地布局
![image](../images/blender/Make_UV_Straight.png)
* 问题解决:安装插件[UVToolkit](https://github.com/oRazeD/UVToolkit),取消勾选`UV Sync Selection`,全选弯曲的UV孤岛,使用`Straighten UVs`打直UV
![image](../images/blender/Make_UV_Straight_Solution.png)

### 权重绘制
* 使用自动权重以减少工作量,然后在常用姿势和极限姿势下进行权重的修缮.
* 必须打开`options -> Auto Normalized`,使权重和为1。只使用三种笔刷:`Add`、`Subtract`和`Blur`。强度最好设置为0.1。
* 细节处权重绘制可以从`骨骼模式`切换到`点模式`,并且将视窗切换到`线框模式`以方便操作;例如:大腿和短裤在接缝处的两组点应该是重叠的,可以对相应点进行`Add`和`Subtract`以修缮权重。
![image](../images/blender/Rig_Weight_Paint.png)

### 绑定和导出
* 问题描述:绑定时为了方便,需要保持各个部分的分离；但是导出时，希望作为一个整体(交由后续的动画制作/游戏引擎的导入)，并且如果需求变动仍需要有能力分离为各个部分再次编辑。
* 问题解决:为每个部分添加材质(命名规则`****_Rig`),使用`control + j`合并各个部分为一个整体，执行分离操作时，选择按材质分离即可。注意:材质添加需要在建模文件中完成,然后同步到绑定文件。

### 骨骼的精确定位
* 使用`Shift + s -> Cursor to Selected`将游标定位到精确位置，进入骨架的`Edit Mode`，选择骨骼的`Head`或`Tail`,使用`Shift + s -> Selected To Cursor`将骨骼精确定位到游标位置。

### 在Rigfy上添加自定义骨骼
* 问题描述:人物模型上的许多小挂件(例如:手表、背包等),希望添加专属的额外骨骼与之绑定，而非将小挂件直接绑定到Rigfy人体骨骼上。
* 问题解决:
  1. `Shift + a`添加单个骨骼(属于新骨架),更改`Bone Collection`为`AttachBones_*****`格式。
  ![image](../images/blender/Add_Custom_Bone_To_Rigfy01.png)
  2. 切换到`Pose Mode`更改相应骨骼的`Rigfy Type`为`basic.super_copy`,勾选`Control`表示会生成`CTRL-***`类型的Rigfy控制骨、通过`Widget`自定义骨骼的形状、勾选`Deform`表示会生成`DEF-***`Rigfy控制骨、`Relink Constraints`对于只有一根骨骼来说暂不需要设置。
  ![image](../images/blender/Add_Custom_Bone_To_Rigfy02.png)
  3. 使用`control + j`合并新增骨架(只有一根骨骼)到Rigfy的原型骨架`metarig`,在`metarig`的`骨架`属性页签，设置新增`Bone Collection`的UI位置。
  ![image](../images/blender/Add_Custom_Bone_To_Rigfy03.png)
  4. 合并之后的`metarig`切换的`Edit Mode`设置新增骨骼与`Rigfy`原型骨架的骨骼之间的父子关系。
  ![image](../images/blender/Add_Custom_Bone_To_Rigfy04.png)
  5. 点击`Re-Generate Rig`重新生成Rigfy骨架`Rig`,依然会保留之前已经绘制好的权重。(重新生成Rig需要保证`Rig`不是隐藏且可选状态)
  ![image](../images/blender/Add_Custom_Bone_To_Rigfy05.png)
  6. 选择重新生成的`Rig`,切换到`Pose Mode`,检查UI和父子关系是否正确。
  ![image](../images/blender/Add_Custom_Bone_To_Rigfy06.png)
  7. 最后进行权重绘制。
  ![image](../images/blender/Add_Custom_Bone_To_Rigfy07.png)
  8. 参考视频:[[Blender 4.0 RIGIFY] ＃6-1: Custom Rigs (theory)](https://www.youtube.com/watch?v=Cq2Vw6EFXy0)
  9. 关于更复杂的(比如:头发的物理模拟如何加入Rigfy骨架)，可参考视频:[blender进阶丨头发和衣服动画物理模拟结算](https://www.bilibili.com/video/BV16G4y1z7BD/?spm_id_from=333.1387.favlist.content.click&vd_source=b9589ad635db7dddd215259c55a8a09c)
  10. 过程中需要注意原始文件`***_AttachBones`和`Metarig`的备份

# Unity优化建议
* Optimize your geometry: don’t use any more triangles than necessary, and try to keep the number of UV mapping seams and hard edges (doubled-up vertices) as low as possible. For more information, see [Creating models for optimal performance](https://docs.unity3d.com/2022.3/Documentation/Manual/ModelingOptimizedCharacters.html).
* Use the Level Of Detail system.