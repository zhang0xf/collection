# 多路IO

## select
```
int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
```
```
struct timeval {
	long tv_sec; /* seconds */
	long tv_usec; /* microseconds */
};
```
* **select**能监听的文件描述符个数受限于FD_SETSIZE(1024)
* **nfds**: 监控的文件描述符集里最大文件描述符加1
* **readfds**: 监控有读数据到达文件描述符集合(bitmap)
* **writefds**: 监控写数据到达文件描述符集合
* **exceptfds**: 监控异常发生达文件描述符集合
* **timeout**: 阻塞监控时间(NULL表示阻塞)
* 文件描述符相关操作
  * `void FD_CLR(int fd, fd_set *set);`
  * `int FD_ISSET(int fd, fd_set *set);`
  * `void FD_SET(int fd, fd_set *set);`
  * `void FD_ZERO(fd_set *set);`

## poll
```
int poll(struct pollfd *fds, nfds_t nfds, int timeout);
```
```
struct pollfd {
	int fd; /* 文件描述符 */
	short events; /* 监控的事件 */
	short revents; /* 监控事件中满足条件返回的事件 */
};
```
* **events**:
  * `POLLIN`: `POLLRDNORM | POLLRDBAND`
  * `POLLRDNORM`: 数据可读
  * `POLLRDBAND`: 优先级带数据可读
  * `POLLPRI`: 高优先级可读数据
  * `POLLOUT`: 普通或带外数据可写
  * `POLLWRNORM`: 数据可写
  * `POLLWRBAND`: 优先级带数据可写
  * `POLLERR`: 发生错误
  * `POLLHUP`: 发生挂起
  * `POLLNVAL`: 描述字不是一个打开的文件
* **nfds**: 监控数组中有多少文件描述符需要被监控
* **timeout**: 毫秒级
  * `timeout = -1`: 阻塞等待
  * `timeout = 0`: 立即返回，不阻塞进程
  * `timeout > 0`: 等待指定毫秒数

## epoll
```
struct eventpoll {
    ...
    wait_queue_head_t wq; // epoll_wait()等待队列
    ...
    struct list_head rdllist; // 就绪文件列表
    struct rb_root rbr; // 红黑树管理所有被监听的文件
    ...
};
```
```
int epoll_create(int size)
```
* **size**: 监听的文件描述符的个数
* **return**: eventpoll对象的句柄
```
typedef union epoll_data {
  void *ptr;
  int fd;
  uint32_t u32;
  uint64_t u64;
} epoll_data_t;
```
```
struct epoll_event {
  __uint32_t events; /* Epoll events */
	epoll_data_t data; /* User data variable */
};
```
```
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)
```
* **epfd**: `epoll_creat`创建的文件句柄
* **op**:
  * EPOLL_CTL_ADD;
  * EPOLL_CTL_MOD;
  * EPOLL_CTL_DEL;
* **fd**: 要监听的文件句柄
* **event**: 监听的事件
  * `EPOLLIN`: 表示对应的文件描述符可以读
  * `EPOLLOUT`: 表示对应的文件描述符可以写
  * `EPOLLPRI`: 表示对应的文件描述符有紧急的数据可读
  * `EPOLLERR`: 表示对应的文件描述符发生错误
  * `EPOLLHUP`: 表示对应的文件描述符被挂断
  * `EPOLLET`: 表示边缘触发模式(就绪fd不重复通知)
  * `EPOLLONESHOT`: 表示只监听一次
```
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout)
```
* **events**: 存放就绪文件列表
* **maxevents**: events数组大小
* **timeout**:
  * `timeout = -1`: 阻塞
  * `timeout = 0`: 立即返回，非阻塞
  * `timeout > 0`: 指定毫秒
* **return**: 返回就绪fd数量，时间到时返回0，出错返回-1

## reference
* [epoll-principle](https://github.com/liexusong/linux-source-code-analyze/blob/master/epoll-principle.md)