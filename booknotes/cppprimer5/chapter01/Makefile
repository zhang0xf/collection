# 获取当前目录下的所有 .cpp 文件
SRCS := $(wildcard *.cpp)

# 去掉 .cpp 后缀，生成可执行文件名
BINS := $(SRCS:.cpp=)

# 编译器和编译选项
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -g

.PHONY: all clean

# 默认目标：构建所有可执行文件
all: $(BINS)

# 规则：每个 .cpp 编译为一个同名的可执行文件
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# 清理所有生成的可执行文件
clean:
	rm -f $(BINS)
	rm -rf ./standard_io.dSYM
