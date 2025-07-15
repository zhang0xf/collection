#指定编译器选项
CC = gcc
CFLAGS = -Wall -g -fPIC

# 目录设置
WORKDIR = .
ASN1 = $(WORKDIR)/asn1
INIPARSER = $(WORKDIR)/iniparser
SOCKET = $(WORKDIR)/socket
LIBDIR = $(WORKDIR)/lib

# Include路径
INCFLAG = -I$(WORKDIR) $(ASN1) $(INIPARSER) $(SOCKET)

# 需要链接的动态库
LIBS = -L$(LIBDIR) -lder -liniparser -lsocket
RPATH = -Wl,-rpath,$(LIBDIR)

# 源文件分类
CLIENT_SRCS = client.c client_initialize.c teacher_code.c
SERVER_SRCS = server.c server_initialize.c teacher_code.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# 默认目标
default: all

all: prepare_libs client_main server_main

# 编译共享库（由各子目录自己的 Makefile 完成）
prepare_libs:
	make -C $(ASN1)
	make -C $(INIPARSER)
	make -C $(SOCKET)
	mkdir -p $(LIBDIR)
	cp $(ASN1)/libder.so $(LIBDIR)/
	cp $(INIPARSER)/libiniparser.so $(LIBDIR)/
	cp $(SOCKET)/libsocket.so $(LIBDIR)/

# 编译 client
client_main: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(RPATH) $(LIBS) $^ -o $@

# 编译 server
server_main: $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(RPATH) $(LIBS) $^ -o $@

# .c -> .o 规则
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY:clean

clean:
	rm -f *.o client_main server_main
	make -C $(ASN1) clean
	make -C $(INIPARSER) clean
	make -C $(SOCKET) clean
	rm -rf $(LIBDIR)