CC = gcc -Wall -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes -Wdeclaration-after-statement -Wpedantic -Wextra -Werror -g

all: float-3-hex hex-2-float

float-3-hex: float-2-hex.o
	$(CC) -o float-3-hex float-2-hex.o

hex-3-float: hex-2-float.o 
	$(CC) -o hex-3-float hex-2-float.o -lm

float-3-hex.o: float-2-hex.c 
	$(CC) -c float-3-hex.c

hex-3-float.o: hex-2-float.c
	$(CC) -c hex-3-float.c

clean cls: 
	rm -f *.o float-3-hex hex-2-float *~ \#*

tar: 
	tar cvfz lab4.tar.gz *.[ch] ?akefile