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

## remove dir/files from remote repo, and add to .gitignore
* `git rm [-r] --cached 'dir/files'`
* `git commit -m "commit message"`
* `git push origin 'remote branch'`

## reference
* [add locally host code](https://docs.github.com/en/get-started/importing-your-projects-to-github/importing-source-code-to-github/adding-locally-hosted-code-to-github)

# SVN操作规范

## install ssubversion
* `brew install subversion`

## create svn repo
* `svnadmin create /Users/zhangfei/SubversionServe/Zeri`

## modify configs
* `vim svnserve.conf`
* `vim passwd`
* `vim authz`

## start svn server
* `svnserve -d -r /Users/zhangfei/SubversionServe/Zeri`

## kill svn server
* `killall svnserve`

## checkout svn repo
* `svn checkout file:///Users/zhangfei/SubversionServe/Zeri /Users/zhangfei/Zeri/develop/code/Zeri/Assets/Resources/Arts`

## svn commands
* `svn update`
* `svn status`
* `svn add --force path/to/dir`
* `svn add --force .`
* `svn status`
* `svn commit -m "commit message"`
* `svn log`
* [SVN常用命令](https://svnbucket.com/posts/svn-commands-tutorial/)