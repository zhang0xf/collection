# Sheet Parser

### Build
* [optional]`go env -w GO111MODULE=on`
* [optional]`go env -w GOPROXY=https://goproxy.io,direct`
* `go mod init parser`
* `go get github.com/tealeg/xlsx`
* `go get github.com/kai1987/go-text-censor`
* `go mod tidy`

### 搭建工作区
* 另见:[itcast README.md](../itcast/README.md)
* 不同点在于:需要添加`sheetparser/.vscode/settings.json`以及修改`collection/collection.code-workspace`工作区文件来使`gopls`插件的语言分析器只作用于`collection/sheetparser`子文件夹以成功去除编辑器警告(注意:该警告不影响go项目的编译,运行和调试)
* 使用`Makefile`指令替代`go`指令(简化常用构建流程、跨平台统一构建、更易与CI/CD工具集成):
  * `make`/`make build`: 编译`main.go`为`bin/parser`
  * `make clean`: 删除`bin/parser`
  * `make fmt`: 格式化所有 Go 文件
  * `make tidy`: 清理无用依赖
  * `make test`: 运行所有子包测试