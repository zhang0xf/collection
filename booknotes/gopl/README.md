# The Go Programming Language

* 参考: [Go语言圣经](https://golang-china.github.io/gopl-zh/index.html)

### 初始化项目
* `cd booknotes/gopl`
* `go mod init gopl`

### 编译所有示例代码
* 切换到“根目录”:`cd booknotes/gopl`
* 构建可执行程序(**Makefile递归**):`make`

### 编译单个章节的示例代码
* 切换到“章节目录”:`cd booknotes/gopl/chapter01`
* 构建可执行程序:`make`

### 调试单个示例代码
* 选中.go文件(hello_world.go)
* `F5`进入调试(无论是否使用`make`生成可执行程序，均可调试`.go`文件)