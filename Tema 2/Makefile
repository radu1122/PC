CC=gcc
CFLAGS=-Wall -Wextra -std=c99
TARGETS=star_dust

build: $(TARGETS)

star_dust: star_dust.c
	$(CC) $(CFLAGS) star_dust.c -o star_dust

clean:
	rm -f $(TARGETS)
