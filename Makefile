CC = gcc
CFLAGS = -g -Wall
LFLAGS = -lSDL2

BIN = bin/
SRC = src/
RSC = rsc/

all: client

client: $(SRC)client.c
	$(CC) $(CFLAGS) -o $(BIN)client $(SRC)client.c $(SRC)base2d.c $(LFLAGS)
