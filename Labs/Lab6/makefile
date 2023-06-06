CC = gcc
CFLAGS = -c -Wall -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes -Wdeclaration-after-statement -Wextra -Werror -Wpedantic
LDFLAGS = -lm  

all: sebm

sebm: sebm.o
	$(CC) sebm.o -o sebm $(LDFLAGS)

sebm.o: sebm.c
	$(CC) $(CFLAGS) sebm.c

clean:
	rm -rf *o sebm

tar: 
	tar cvfz lab6.tar.gz *.[ch] ?akefile
	