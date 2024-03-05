# HTTP
* 参考网站 : [https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Overview](https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Overview)

## HTTP请求消息
### 请求行
* `POST /api/post HTTP/1.1` : 请求方式、URL、协议版本

### 请求头部
* 键值对方式
* 常见头部:

| 常见头部字段 | 说明 |
| :-----:| :---- |
| Host | 要请求的服务器域名 |
| Connection | 客户端与服务器的链接方式(close/keepalive) |
| Content-Length | 用来描述请求体的大小 |
| **Accept** | 客户端可识别的响应内容类型列表 |
| **User-Agent** | 产生请求的浏览器类型 |
| **Content-Type** | 客户端告诉服务器实际发送的数据类型 |
| Accept-Encoding | 客户端可接受的内容压缩编码形式 |
| **Accept-Language** | 用户期望获得的自然语言的优先顺序 |

```
GET / HTTP/1.1
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
Accept-Encoding: gzip, deflate, br
Accept-Language: en-US,en;q=0.9,zh-CN;q=0.8,zh;q=0.7
Cache-Control: max-age=0
Connection: keep-alive
Host: localhost
If-None-Match: W/"17-twkSb+dmNavVKUC2pIiLIXnV8oM"
sec-ch-ua: "Chromium";v="104", " Not A;Brand";v="99", "Google Chrome";v="104"
sec-ch-ua-mobile: ?0
sec-ch-ua-platform: "macOS"
Sec-Fetch-Dest: document
Sec-Fetch-Mode: navigate
Sec-Fetch-Site: none
Sec-Fetch-User: ?1
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.0.0 Safari/537.36
```
### 空行
* 标识请求头部结束,分割请求头部与请求体.
* GET请求没有请求体.

### 请求体
略

## HTTP响应消息
### 状态行
* `HTTP/1.1 200 OK` : HTTP协议版本、状态码、状态码的描述文本

### 响应头部
* 键值对方式
```
HTTP/1.1 200 OK
X-Powered-By: Express
Content-Type: text/html; charset=utf-8
Content-Length: 23
ETag: W/"17-hqTiuz6EIVkU2ajz0DIDBxu3iB4"
Date: Tue, 16 Aug 2022 13:23:10 GMT
Connection: keep-alive
Keep-Alive: timeout=5
```

### 空行
* 标识响应头部结束,分割响应头部和响应体.

### 响应体
略

## HTTP请求方法
* 用来表明对服务器上的资源执行的操作
* 所有的请求方法:

| 序号 | 方法 | 描述 |
| :--: | :-: | :---|
| 1 | **GET** | (查询)发送请求获取服务器上的资源,请求体中不会包含请求数据,请求数据存放在协议头中 |
| 2 | **POST** | (新增)向服务器提交资源,数据包含在请求体中提交给服务器 |
| 3 | **PUT** | (修改)向服务器提交资源,并用提交的新资源,替换掉服务器对应的旧资源 |
| 4 | **DELETE** | (删除)请求服务器删除指定的资源 |
| 5 | HEAD | HEAD方法请求一个与GET请求的响应相同的服务器响应,但没有响应体 |
| 6 | OPTIONS | 获取http服务器支持的http请求方法,允许客户端查看服务器的性能(比如:ajax跨域时的预检) |
| 7 | CONNECT | 建立一个由目标资源标识的服务器隧道 |
| 8 | TRACE | 沿着目标资源的路径执行一个消息回环测试,主要用于测试和诊断 |
| 9 | PATCH | 是对PUT方法的补充,用来对已知资源进行局部更新 |

## HTTP响应状态码
* 用来标识响应的状态.
* 状态码由3个十进制数字组成,第1个数字定义状态码的类型,后2个数字用来对状态码进行细分.
* 共分为5种类型:

| 分类 | 分类描述 |
| :--: | :-- |
| 1** | **信息**,服务器收到请求,需要请求者继续进行操作(较少遇到) |
| 2** | **成功**,操作被成功接受,并处理. |
| 3** | **重定向**,需要进一步的操作以完成请求. |
| 4** | **客户端错误**,请求包含语法错误,或无法完成请求 |
| 5** | **服务器错误**,服务器在处理请求的过程中发生了错误 |

### 2**成功相关的响应状态码
* 表示服务器已经成功接收请求并进行处理.
* 常见状态码:

| 状态码 | 状态码英文名称 | 中文描述 |
| :--: | :--: | :-- |
| 200 | OK | **请求成功**,一般用于GET与POST请求 |
| 210 | Created | **已创建**,成功请求并创建了新的资源,通常用于POST和PUT请求 |

### 3**重定向相关的响应状态码
* 要求客户端进行重定向,需要进一步操作以完成资源的请求.
* 常见状态码:

| 状态码 | 状态码英文名称 | 中文描述 |
| :--: | :--: | :-- |
| 301 | Moved Permanetly | **永久移动**,请求的资源已被永久移动到新的URL,返回给客户端的信息包括新的URL,浏览器会自动重定向到新URL,今后任何新的请求都应使用新的URL代替 |
| 302 | Found | **临时移动**,与301类似,但资源只是临时被移动,客户端应继续使用原有的URL |
| 304 | Not Modified | **未修改**,所请求的资源未修改,服务器返回状态码时,不会返回任何资源(响应消息中不包含响应体),客户端通常会缓存访问过的资源.|

### 4** 客户端错误相关的响应状态码
* 客户端的请求有非法内容,从而导致这次请求失败.
* 常见状态码:

| 状态码 | 状态码英文名称 | 中文描述 |
| :--: | :--: | :-- |
| 400 | Bad Request | 1.语义有误,当前请求无法被服务器理解.除非进行修改,否则客户端不应该重复提交这个请求. |
| 401 | Unauthorized | 当前请求需要用户验证 |
| 403 | Forbidden | 服务器已经理解请求,但是拒绝执行它. |
| **404** | Not Found | 服务器无法根据客户端的请求找到资源(网页) |
| 408 | Request Timeout | 请求超时,服务器等待客户端发送的请求时间过长,超时 |

### 5** 服务器端错误相关的响应状态码
* 表示服务器未能正常处理客户端的请求而出现意外错误
* 常见状态码:

| 状态码 | 状态码英文名称 | 中文描述 |
| :--: | :--: | :-- |
| 500 | Internal Server Error | 服务器内部错误,无法完成请求. |
| 501 | Not Implemented | 服务器不支持该请求方法,无法完成请求.只有GET和HEAD请求方法是要求每个服务器必须支持的,其他方法在不支持的服务器上会返回501. |
| 503 | Service Unavailable | 由于超载或系统维护,服务器暂时地无法处理客户端的请求. |