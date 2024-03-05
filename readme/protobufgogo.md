# protobufgogo

#### 1.更改go代理
* `go env -w GO111MODULE=on`
* `go env -w GOPROXY=https://goproxy.io,direct`

## 安装protoc

### 方法1：从源码编译protoc

* 参考：[https://github.com/zhang0xf/protobuf-cpp/blob/main/README.md](https://github.com/zhang0xf/protobuf-cpp/blob/main/README.md)

### 方法2：下载release版本
* [Protobuf Release](https://github.com/protocolbuffers/protobuf/releases/tag/v3.19.1)
* 获取release包（或手动下载）：`wget https://github.com/protocolbuffers/protobuf/releases/download/v3.19.1/protoc-3.19.1-linux-x86_64.zip`
* 解压缩: `unzip protoc-3.19.1-linux-x86_64.zip -d protoc-3.19.1-linux-x86_64`
* 设置bin到PATH: `cp  protoc-3.19.1-linux-x86_64/bin/protoc /user/local/bin`
* 设置include到PATH: `cp  protoc-3.19.1-linux-x86_64/include/* /user/local/include`

## 安装protoc-gen-go插件
* 安装protobuf库文件（普通包）: `go get google.golang.org/protobuf`
* go1.16以下版本，安装protoc-gen-go插件(二进制): `go get github.com/golang/protobuf/protoc-gen-go`
* go1.17版本，安装protoc-gen-go插件（二进制）: `go install github.com/golang/protobuf/protoc-gen-go@latest`
* 设置bin到PATH: `cp $(GOPATH)/bin/proto-gen-go /user/local/bin/`即`cp /root/go/bin/protoc-gen-go /usr/local/bin/`
* 编译.proto文件(略)

## 安装protoc-gen-gofast插件
* 安装gogoprotobuf库: `go get github.com/gogo/protobuf/proto`
* 安装gogoprotobuf库[可选]: `go get github.com/gogo/protobuf/gogoproto`
* go1.16以下版本，安装protoc-gen-gofast插件(二进制):`go get github.com/gogo/protobuf/protoc-gen-gofast`
*  go1.17版本，安装protoc-gen-go插件（二进制）: `go install github.com/gogo/protobuf/protoc-gen-gofast@latest`
* 设置bin到PATH: `cp $(GOPATH)/bin/proto-gen-gofast /user/local/bin/`即`cp /root/go/bin/protoc-gen-gofast /usr/local/bin/`
* 编译.proto文件

## 参考
* [https://github.com/gogo/protobuf](https://github.com/gogo/protobuf)
* [https://zhuanlan.zhihu.com/p/362436742](https://zhuanlan.zhihu.com/p/362436742)
* [https://yushuangqi.com/blog/2017/golangshi-yong-protobuf.html](https://yushuangqi.com/blog/2017/golangshi-yong-protobuf.html)