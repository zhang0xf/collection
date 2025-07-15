# iniparser/Makefile

# 编译设置
CC = gcc
CFLAGS = -Wall -g -fPIC
INCFLAGS = -I.

# 文件名
LIB = libiniparser.so
TEST_BIN = test

# 源文件（用于库）
LIB_SRCS = iniparser.c dictionary.c
LIB_OBJS = $(LIB_SRCS:.c=.o)

# 测试源文件（不加入库）
TEST_SRCS = functest.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

# 默认目标：构建共享库
all: $(LIB)

# 构建共享库
$(LIB): $(LIB_OBJS)
	$(CC) -shared $^ -o $@

# 构建测试程序（可选）
test: $(LIB_OBJS) $(TEST_OBJS)
	$(CC) $^ -o $(TEST_BIN)

# 通用规则：.c -> .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

# 清理所有中间文件和输出
.PHONY: clean
clean:
	rm -f $(LIB_OBJS) $(TEST_OBJS) $(LIB) $(TEST_BIN)
