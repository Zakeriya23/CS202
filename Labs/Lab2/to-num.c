//Zakeriya Muhumed || PSU CS201 || Lab 2 || Char in octal, decimal, hex
#include <stdio.h>
#include <string.h>
#define STRLEN 300

int main(void){

   char str1[STRLEN];
   while(fgets(str1,STRLEN,stdin)!=NULL){
   int size= strlen(str1) - 1;

   printf("character output\n");
    for(int i = 0; i < size; ++i){
        printf("%c ", str1[i]);
    }
    printf("\noctal output\n");
    for(int i = 0; i < size; ++i){
        printf("0%03o ", str1[i]);
    }
    printf("\ndecimal output\n");
    for(int i = 0; i < size; ++i){
        printf("%3d ", str1[i]);
    }
    printf("\nhex output\n");
    for(int i = 0; i < size; ++i){
        printf("0x%02x ", str1[i]);
    }
    printf("\n");
   }

    return 0;
}
