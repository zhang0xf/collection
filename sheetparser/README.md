# Sheet Parser

一个用go编写的excel表格解析模块

### 切换国内代理【可选】
* `go env -w GO111MODULE=on`
* `go env -w GOPROXY=https://goproxy.io,direct`

### 初始化项目
* `go mod init parser`
* `go get github.com/tealeg/xlsx`
* `go get github.com/kai1987/go-text-censor`
* `go mod tidy`

### 编译和运行
编译：`make`指令替代`go`指令（简化常用构建流程、跨平台统一构建、更易与CI/CD工具集成）
* `make`/`make build`
* `make clean`
* `make fmt`（按标准格式格式化所有代码文件）
* `make tidy`
* `make test`

运行：略

### 搭建调试环境
参考：[搭建Python调试器](../alieninvasion/README.md#搭建调试环境)

注意：调试器配置(`launch.json`)中的`"program"`字段需要指向`sheetparser/main.go`所在的目录或直接指向`sheetparser/main.go`，而非编译生成的可执行文件！

### 编辑器警告去除
在工作区文件`collection.code-workspace`中添加`"directoryFilters"`字段来告诉`gopls`编辑器扩展应该对哪些子文件夹项目使用`语言分析器`(注意：该警告只有在`运行和调试`界面选择了`launch package(sheetparser)`调试器时才会在编辑器出现，且该警告并不影响go项目的编译、运行和调试)