CC = g++
WORKDIR = .
INCFLAG = -I$(WORKDIR)
SRCDIR = $(WORKDIR)
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -lstdc++ -std=c++11

SRCS = $(wildcard $(SRCDIR)/*.cpp)
NODIR = $(notdir $(SRCS))
OBJS = $(patsubst %.c, %.o, $(NODIR))

BIN = main

$(BIN):$(OBJS)
	$(CC) $(LIBS) $^ -o $@

%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

.PHONY:clean

clean:
	rm $(WORKDIR)/$(BIN)
	
