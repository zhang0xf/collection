# 编译器和路径设置
CC = g++
WORKDIR = .
INCFLAG = -I$(WORKDIR)
SRCDIR = $(WORKDIR)
CFLAGS = -Wall -Wextra -g
LIBS = -lstdc++ -std=c++11

# 源文件和对象文件
SRCS = $(wildcard $(SRCDIR)/*.cpp)
NODIR = $(notdir $(SRCS))
OBJS = $(patsubst %.cpp, %.o, $(NODIR))

# 最终可执行文件名
BIN = main

# 链接目标文件
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

# 编译每个 .cpp 为 .o
%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

# 清理
.PHONY: clean
clean:
	@rm -f $(BIN) *.o
