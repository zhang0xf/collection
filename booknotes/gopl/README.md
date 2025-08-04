# The Go Programming Language

《The Go Programming Language》随书笔记及代码整理

Github在线书籍: [Go语言圣经](https://golang-china.github.io/gopl-zh/index.html)

### 切换国内代理【可选】
* `go env -w GO111MODULE=on`
* `go env -w GOPROXY=https://goproxy.io,direct`

### 初始化项目
* `cd collection/booknotes/gopl`
* `go mod init gopl`
* `go mod tidy`

### 编译代码
* `cd collection/booknotes/gopl`
* <del>`chmod +x generate_makefiles.py`（确保具有执行权限）</del>【无需】
* `make generate`（生成Makefile）
* `make`

### 运行项目
略

### 搭建调试环境
参考：[搭建Python调试器](../../alieninvasion/README.md#搭建调试环境)

注意：调试某一示例代码时，必须先选中`main()`函数所在文件（例如：`chapter01/hello_world/main.go`）