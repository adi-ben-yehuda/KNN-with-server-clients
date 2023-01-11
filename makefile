SH = bash
CFLAGS = -g
LDFLAGS = -lm
CC = g++

all: server.out client.out

# Write Makefile rules to compile the client and server program,
server.out: server.o File.o MaxHeap.o Distance.o
	$(CC) $(LDFLAGS) $^ -o $@ -std=c++11
client.out: client.o File.o MaxHeap.o Distance.o
	$(CC) $(LDFLAGS) $^ -o $@ -std=c++11
server.o: server.cpp File.h MaxHeap.h Distance.h
	$(CC) -c $(CFLAGS) $< -o $@
client.o: client.cpp File.h MaxHeap.h Distance.h
	$(CC) -c $(CFLAGS) $< -o $@
.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf server.out
	rm -rf client.out

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;
