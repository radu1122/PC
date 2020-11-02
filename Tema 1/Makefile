# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

build:
	$(CC) $(CFLAGS) ninel.c -o ninel
	$(CC) $(CFLAGS) vectsecv.c -o vectsecv
	$(CC) $(CFLAGS) codeinvim.c -o codeinvim
	$(CC) $(CFLAGS) nomogram.c -o nomogram

clean:
	rm -f ninel vectsecv codeinvim nomogram
