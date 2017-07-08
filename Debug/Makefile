#!/bin/makefile

OFILES=../Object.o main.o
OFILESFIN=Object.o main.o
EXEC=debug

LDFLAGS=-g
CFLAGS=-Wall -Wextra -ansi -pedantic

CC=gcc

CLEAN=*.o *~

all:$(EXEC)

$(EXEC):$(OFILES)
	$(CC) $(OFILESFIN) -o $@ $(LDFLAGS)

%.o:%.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm $(CLEAN)
clear: clean

cleaner:
	rm $(EXEC) $(CLEAN)
