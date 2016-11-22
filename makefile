### C Arguments
CC=gcc
CFLAGS=-std=gnu11 -Wall -lm

### Program Arguments
NAME=main

### Compiler Arguments
INCLUDE_PATH=include
SRC_PATH=src

all: merge

merge: main.o rational.o
	$(CC) -o $(NAME) main.o rational.o $(CFLAGS)

rational.o: $(SRC_PATH)/rational.c $(INCLUDE_PATH)/rational.h
	$(CC) -c $(SRC_PATH)/rational.c -I/$(INCLUDE_PATH)

main.o: $(SRC_PATH)/main.c
	$(CC) -c $(SRC_PATH)/main.c
