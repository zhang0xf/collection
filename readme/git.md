# Github 操作规范及常见问题整理

### 新建本地仓库并推送的远端
参考：[将本地托管代码添加到 GitHub](https://docs.github.com/zh/migrations/importing-source-code/using-the-command-line-to-import-source-code/adding-locally-hosted-code-to-github)

<!-- ## new branch to develop
* `git branch -a` : 查看所有的分支
* `git branch 'new_branch'` : 创建新分支
* `git checkout main` : 基于main分支创建新分支
* `git checkout 'new_branch'` : 切换到新分支
* `git add . && git commit -m "commit message"` : 完成工作

## local branch merge
* `git checkout main` : 切换到main分支
* `git merge 'new_branch'` : 将new_branch分支合并到main分支

## push branch to origin
* `git push -u origin 'new_branch'` : 推送本地分支到远端仓库

## remote branch merge
* 在github页面发起pullrequest请求

## 移除远端分支的目录/文件
* `git rm [-r] --cached 'dir/files'`
* `git commit -m "commit message"`
* `git push origin 'remote branch'` -->

### 清理仓库中的历史文件【慎重使用】
问题描述：`git clone`会将整个仓库的历史记录（完整的commit DAG + 所有文件快照）下载到`.git`目录中，包括那些已经被`git delete`的文件。如果提交历史中存在很多大的图片或二进制文件，即使在后来的提交中被删除了，也仍然会导致仓库变大，`git clone`操作变慢。

解决方法：
* `cd “仓库根目录“`
* 确保本地已无修改：`git status`
* 确认`.git`目录大小：`du -sh .git`【可选】
* 查看“历史中存在、当前已删除”的文件
<div style="margin-left: 2em"> <!--代码块的缩进-->

```shell
git log --diff-filter=D --summary | grep delete
```
</div>

* 提取Git历史中所有曾出现过的图片路径（以图片文件为例）：
<div style="margin-left: 2em">

```shell
git log --all --pretty=format: --name-only \
  | grep -E '\.(gif|png|jpg|jpeg|bmp)$' \
  | sort -u > all_images_in_history.txt
```
</div>

* 生成当前Git跟踪的图片文件列表
<div style="margin-left: 2em"> 

```shell
git ls-files | grep -Ei '\.(gif|png|jpg|jpeg|bmp)$' | sort > current_images.txt
```
</div>

* 对比历史和当前，找出已被删除的图像文件
<div style="margin-left: 2em"> 

```shell
comm -23 all_images_in_history.txt current_images.txt > deleted_images.txt
```
</div>

* 安装`git-filter-repo`
<div style="margin-left: 2em"> 

```shell
brew install git-filter-repo
```
</div>

* 备份原始仓库【保险起见】：
<div style="margin-left: 2em"> 

```shell
cd ..
cp -r collection collection_backup
```
</div>

* 克隆一份用于清理历史的新仓库（因为`git-filter-repo`工具要求`operate on a fresh clone`。参数`--no-local`表示强制要求Git复制仓库对象而非出于优化考虑使用“硬链接”。此外，`filtered-repo.git`是一个裸仓库，只包含`.git`，不包含工作文件）：
<div style="margin-left: 2em"> 

```shell
git clone --mirror --no-local ./collection filtered-repo.git
```
</div>

* 进入克隆并执行清理命令（注意：这是**不可逆**操作！Git的`commit`历史将被重写，因为你从历史中移除了某些文件的所有痕迹。其次所有的`commit`的`SHA`哈希值都可能改变。也会影响`Github`网页端的`Contributions`（贡献图/小绿点））
<div style="margin-left: 2em"> 

```shell
cd filtered-repo.git
git filter-repo --paths-from-file ../collection/deleted_images.txt --invert-paths--invert-paths
```
</div>

* 对比`log`输出，确认文件是否已被彻底删除（以`deleted_images.txt`文件中列出的`images/blender/Add_Custom_Bone_To_Rigfy01.png`，`log`不一致，则表明`git-filter-repo`已经重写了历史记录）
<div style="margin-left: 2em"> 

```shell
cd ../collection
git log -- images/blender/Add_Custom_Bone_To_Rigfy01.png
cd ../filtered-repo.git
git log -- images/blender/Add_Custom_Bone_To_Rigfy01.png
```
</div>

* 将裸仓库克隆为一个正常的工作区【可选：确认`.git`目录是否成功瘦身】
<div style="margin-left: 2em"> 

```shell
cd ..
git clone filtered-repo.git cleaned-collection
cd cleaned-collection
du -sh .git
```
</div>

* 替换远程仓库（这里没有选择新建远程仓库。如果需要保留旧的远程仓库，那么应该选择新建一个远程仓库）
<div style="margin-left: 2em"> 

```shell
git remote set-url origin git@github.com:zhang0xf/collection.git
git remote -v
```
</div>

* 强制推送新历史到远端仓库【WARNNING：这一步会覆盖远程仓库的历史记录，确认协作者已经知情】
<div style="margin-left: 2em"> 

```shell
git push --force origin main
```
</div>

* 如果一切正常，将`"cleaned-collection"`设置为本地的工作区
<div style="margin-left: 2em"> 

```shell
rm -rf collection
mv cleaned-collection collection
```
</div>

* 清理现场（WARNNING：必须确认新仓库没有问题，可以不着急清理）
<div style="margin-left: 2em"> 

```shell
rm -rf filtered-repo.git
rm -rf collection_backup
```
</div>

* 通知协作人员重新克隆：`git clone git@github.com:zhang0xf/collection.git`

实际项目建议：
* 如果历史中虽然有图像/视频，但仓库体积没有大到克隆非常慢，就可以不处理。
* 只做未来的规范，不动历史。写好团队文档，提醒大家不要上传大文件。清理的是“未来的口子”，不是“过去的疤”。

来自开源项目的惯例：
* 图像、音视频文件一旦被误上传，一般不会追究过去，但会从此限制未来。
* 若实在想删历史，建议新建一个无历史的仓库并做一次性迁移。
* 大多数开源项目都不追求仓库的“纯净”历史，只在极端情况下清理。