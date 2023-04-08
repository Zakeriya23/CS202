#include <stdio.h>

// gcc -Wall -g -o f2c f2c.c
// ./f2c 

/*
Fahrenheit Celsius 
32          0.0000
40          4.4444
50          10.000
60          15.1556
100         37.7778
212         100.000
*/

int main(void){
    float fahrenheit = 0.0;
    float celsius = 0.0;
    
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32.0) *5.0/9.0;
    printf("\nCelsius = %.4f\n",celsius);

    return 0;
}
