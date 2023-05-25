CC = gcc -Wall -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes -Wdeclaration-after-statement -Wpedantic -Wextra -Werror -g

all: float-2-hex hex-2-float

float-2-hex: float-2-hex.o
	$(CC) -o float-2-hex float-2-hex.o

hex-2-float: hex-2-float.o 
	$(CC) -o hex-2-float hex-2-float.o -lm

float-2-hex.o: float-2-hex.c 
	$(CC) -c float-2-hex.c

hex-2-float.o: hex-2-float.c
	$(CC) -c hex-2-float.c

clean cls: 
	rm -f *.o float-2-hex hex-2-float *~ \#*

tar: 
	tar cvfz lab5.tar.gz *.[ch] ?akefile