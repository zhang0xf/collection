# The Go Programming Language

* 参考: [Go语言圣经](https://golang-china.github.io/gopl-zh/index.html)

### 初始化项目
* `cd booknotes/gopl`
* `go mod init gopl`

### 编译所有示例代码
* 切换到“根目录”:`cd booknotes/gopl`
* 确保`gopl/generate_makefiles.py`具有执行权限: `chmod +x generate_makefiles.py`
* 为所有示例(例如:`gopl/chapter01/hello_world/main.go`)生成`Makefile`文件(通过`Python`脚本创建): `make generate`
* 为所有示例构建可执行程序(**Makefile递归**):`make`

### 调试单个示例代码
* 选中.go文件(hello_world.go)
* `F5`进入调试(无论是否使用`make`生成可执行程序，均可调试`.go`文件)