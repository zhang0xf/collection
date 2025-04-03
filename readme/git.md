# github操作规范

## new branch to develop
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
* `git push origin 'remote branch'`

## reference
* [add locally host code](https://docs.github.com/en/get-started/importing-your-projects-to-github/importing-source-code-to-github/adding-locally-hosted-code-to-github)

># SVN配置
### 安装Subversion
* `brew install subversion`

### 创建SVN仓库
* `svnadmin create /Users/zhangfei/SubversionServe/Zeri`

### 配置SVN仓库
* `vim svnserve.conf`
* `vim passwd`
* `vim authz`

### 启动SVN服务(-d:守护进程的方式)
* `svnserve -d -r /Users/zhangfei/SubversionServe/Zeri`

### 结束SVN服务
* `killall svnserve`

># SVN常用操作
### 检出仓库文件到本地文件夹'Zeri'
* `svn checkout file:///Users/zhangfei/SubversionServe/Zeri /Users/zhangfei/Zeri/develop/code/Zeri/Assets/Resources/Zeri`

### 常用命令
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
* [SVN常用命令](https://svnbucket.com/posts/svn-commands-tutorial/)