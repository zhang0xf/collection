# SVN 操作规范及常见问题整理

### 创建SVN服务
* 安装`subversion`：`brew install subversion`
* 创建仓库：`svnadmin create /Users/zhangfei/.svn/repo`
* 配置仓库：
<div style="margin-left: 2em"> <!--代码块的缩进-->

```shell
cd ~/.svn/repo
vim svnserve.conf
vim passwd
vim authz
```
</div>

* 启动服务（`-d`表示以守护进程的方式）：`svnserve -d -r /Users/zhangfei/.svn/repo`
* 结束服务：`killall svnserve`
* 检出仓库到本地文件夹：`svn checkout file:///Users/zhangfei/.svn/repo **/repo`

### SVN常用命令
参考：[SVN常用命令](https://svnbucket.com/posts/svn-commands-tutorial/)
* `svn update`
* `svn update -r 'veriosn'`
* `svn status`
* `svn add --force path/to/dir`
* `svn add --force .`
* `svn diff [path/to/dir] [-r 'version']`
* `svn revert 'wrong.cpp'`
* `svn revert -R path/to/dir`
* `svn delete path/to/dir [--keep-local]`
* `svn status`
* `svn propset svn:ignore "*.log" .`
* `svn propset svn:global-ignores "*.log" .`
* `svn propset svn:ignore -F 'ignore-rules-file.txt' .`
* `svn propedit svn:ignore .`
* `svn proplist . -v`
* `svn propdel svn:ignore .`
* `svn commit -m "commit message"`
* `svn log -l 5`
* `svn cleanup`
* `svn ls`