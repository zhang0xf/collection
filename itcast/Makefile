#指定编译器选项
CC = gcc
WORKDIR = .
CFLAGS = -Wall -g
ASN1 = $(WORKDIR)/asn1
TEACHER = $(WORKDIR)/asn1/teacher
INIPARSER = $(WORKDIR)/iniparser
SOCKET = $(WORKDIR)/socket
# INCFLAG = -I$(WORKDIR) $(ASN1) $(TEACHER) $(INIPARSER) $(SOCKET)
SRCS = $(wildcard $(WORKDIR)/*.c $(ASN1)/*.c $(TEACHER)/*.c $(INIPARSER)/*.c $(SOCKET)/*.c)
SRCS_FILTER = $(filter-out $(ASN1)/functest.c, $(SRCS))
SRCS_FILTER := $(filter-out $(INIPARSER)/functest.c, $(SRCS_FILTER))
OBJS = $(patsubst %.c, %.o, $(SRCS_FILTER))

default: all

all: main

main: $(OBJS)
#	make -C $(INIPARSER)
#	make -C $(SOCKET)
#	$(CC) -I$(INCLUDES) -L$(LIB) -lder -liniparser -lsocket $^ -o $@
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean

clean:
	rm $(TEACHER)/*.o $(ASN1)/*.o $(INIPARSER)/*.o $(SOCKET)/*.o $(WORKDIR)/*.o $(WORKDIR)/main