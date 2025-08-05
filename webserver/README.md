# WebServer

一个用go编写的网络服务器案例

### 切换国内代理【可选】
* `go env -w GO111MODULE=on`
* `go env -w GOPROXY=https://goproxy.io,direct`

### 初始化项目
* `cd collection/webserver`
* `go mod init nw`
* `go run nw.go`（自动下载依赖并运行）
* `go mod tidy`（清理未使用的依赖，补全遗漏）

### 编译和运行
编译：`make`

运行：略

### 搭建调试环境
参考：[搭建Python调试器](../alieninvasion/README.md#搭建调试环境)

注意：调试器配置(`launch.json`)中的`"program"`字段需要指向`**/main.go`所在的目录或直接指向`**/main.go`，而非编译生成的可执行文件！【详见`launch.json`】

### 去除编辑器警告
参考：[去除编辑器警告](../sheetparser/README.md#编辑器警告去除)