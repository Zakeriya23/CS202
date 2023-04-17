//Zakeriya Muhumed || PSU CS201 || Lab 2 || Char in octal, decimal, hex
#include <stdio.h>

#define STRLEN 300

int main(void){

    char str1[STRLEN]= {'\0'};
    int i =0;
    fgets(str1,STRLEN,stdin);

    printf("character output\n");
    while(str1[i] != '\0'){
       printf("%c ", str1[i++]);
    }
    printf("octal output\n");
     i=0;
     while(str1[i] != '\0'){
     printf("%#o ", str1[i++]);
     }
     printf("\ndecimal output\n");
     i=0;
     while(str1[i] != '\0'){
        printf("%d ", str1[i++]);
     }
     printf("\nhex output\n");
     i=0;
     while(str1[i] != '\0'){
        printf("%#X ", str1[i++]);
     }
     printf("\n");
    
    return 0;
}
