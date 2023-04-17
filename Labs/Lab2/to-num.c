//Zakeriya Muhumed || CS201 || Lab 2

#include <stdio.h>

//gcc -g -Wall -o to-num to-num.c
// ./to-num

#define STRLEN 300

int main(void){

    char str1[STRLEN]= {'\0'};
    int i =0;
    fgets(str1,STRLEN,stdin);
    
    {//Char 
        printf("character output\n");
        while(str1[i] != '\0'){
            printf("%c ", str1[i++]);
        }

    }

    {//Octal
        printf("octal output\n");
        i=0;
        while(str1[i] != '\0'){
                printf("%#o ", str1[i++]);
        }
    }
    {//decimal
        printf("\ndecimal output\n");
        i=0;
        while(str1[i] != '\0'){
                printf("%d ", str1[i++]);
        }
    }
    {//decimal
        printf("\nhex output\n");
        i=0;
        while(str1[i] != '\0'){
                printf("%#X ", str1[i++]);
        }
        printf("\n");
    }

    return 0;
}