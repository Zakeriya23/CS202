#include <stdio.h>
#include <stdlib.h>

// gcc -Wall -g -o endian endian.c
// ./endian


int main(void){

    unsigned int endian = 1;
    char *ecp= (char *) & endian;

    if(ecp[0] == '\0'){
        printf("This is an biug endian architecture\n");
    }
    else{
        printf("This is a little endian architecture\n");
    }


    return EXIT_SUCCESS;
}