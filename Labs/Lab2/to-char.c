//Zakeriya Muhumed || PSU CS201 || Lab 2 || Char in octal, decimal, hex
#include <stdio.h>
#include <string.h>

#define STRLEN 300
int main(void){
    int choice = 0;
    int decimal = 0;
    int octal = 0;
    int hex = 0;
    scanf("%d", &choice);

    switch (choice){
    case 8:
        printf("octal input\n");
        scanf("%o", &octal);
        while(octal != 0){
            printf("%c", octal);
            scanf("%o", &octal);
        } 
        printf("\n"); 
        break;
    case 10:
        printf("decimal input\n");
        scanf("%d", &decimal);
        while(decimal != 0){
            printf("%c", decimal);
            scanf("%d", &decimal);
        }
        printf("\n"); 
        break;
    case 16:
        printf("hex input\n");
        scanf("%x", &hex);
        while(hex != 0){
            printf("%c", hex);
            scanf("%x", &hex);
        } 
        printf("\n"); 
        break;
    }
}
