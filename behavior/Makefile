CC = g++
WORKDIR = .
INCFLAG = -I$(WORKDIR)
SRCDIR = $(WORKDIR)
CFLAGS = -Wall -Wextra -g
# CFLAGS = -Wall -Wextra -Werror -g -O0
LIBS = -lstdc++ -std=c++11

SRCS = $(wildcard $(SRCDIR)/*.cpp)
NODIR = $(notdir $(SRCS))
OBJS = $(patsubst %.cpp, %.o, $(NODIR))

BIN = main

$(BIN):$(OBJS)
	$(CC) $(LIBS) $^ -o $@

%.o:$(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

.PHONY:clean

clean:
	rm $(WORKDIR)/$(BIN) $(WORKDIR)/*.o
	