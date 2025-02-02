CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99
LDFLAGS=-llua -lm

horror: *.o
	$(CC) *.o $(LDFLAGS) -o horror

main.o: main.c main.h
	$(CC) -c main.c $(CFLAGS) -o main.o

clean:
	rm -f ./*.o horror
