
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

same-tree: same-tree.o
	$(CC) $(CFLAGS) -o same-tree same-tree.o

same-tree.o: same-tree.cpp
	$(CC) $(CFLAGS) -c same-tree.cpp

clean:
	rm -rf same-tree same-tree.o
