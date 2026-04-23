CC = gcc
CFLAGS = -Wall -g -Wno-unused-function
LDLIBS = -lm

tp2: tp2.c tp2-tools.c
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

clean:
	rm tp2
