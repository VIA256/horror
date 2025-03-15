CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99
LDFLAGS=

horror:
	$(CC) main.c $(LDFLAGS) -o horror

