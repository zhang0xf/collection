# asn1/Makefile

# 编译器设置
CC = gcc
CFLAGS = -Wall -g -fPIC
INCFLAGS = -I.

# 目标库
OBJS = itcast_asn1_der.o itcastderlog.o
LIB = libder.so

# 默认目标
default: $(LIB)

# 构建动态链接库
$(LIB): $(OBJS)
	$(CC) -shared $^ -o $@

# .c → .o 规则
%.o: %.c
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

# 清理构建产物
.PHONY: clean
clean:
	rm -f $(OBJS) $(LIB)
