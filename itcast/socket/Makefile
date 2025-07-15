# socket/Makefile

# 编译设置
CC = gcc
CFLAGS = -Wall -g -fPIC
INCFLAGS = -I.

# 目标库
LIB = libsocket.so

# 自动获取所有 .c 文件
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

# 默认目标
all: $(LIB)

# 构建共享库
$(LIB): $(OBJS)
	$(CC) -shared $^ -o $@

# .c -> .o 的通用规则
%.o: %.c
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

# 清理
.PHONY: clean
clean:
	rm -f $(OBJS) $(LIB)
