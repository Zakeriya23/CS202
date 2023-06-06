//Zakeriya Muhumed || CS201 || Lab 7

//Librays
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

// gcc -Wall -o ok_mult ok_mult.c
// ./ok_mult

int ok_mult_int(int, int, int *);
int ok_mult_short(short, short, short *);
int ok_mult_short2(short, short, short *);

int main(void){
    //int 
    {
        int x1= 2147483;
        int x2= 10;
        int prod = 0;
        int result = 0;

        result = ok_mult_int(x1, x2, &prod);
        printf("ok_mult_int\tx1: %d\tx2: %d\t\tprod: %d\t\tokay: %s\n", x1,x2, prod, (result==0) ? "yes" : "no");
        assert(result==0);
    }
    {
        int x1= INT_MAX;
        int x2= 1000;
        int prod = 0;
        int result = 0;

        result = ok_mult_int(x1, x2, &prod);
        printf("ok_mult_int\tx1: %d\tx2: %d\tprod: %d\t\tokay: %s\n", x1,x2, prod, (result==0) ? "yes" : "no");
        assert(result==1);
    }

    //Short
    {
        short x1= 2000;
        short x2= 10;
        short prod = 0;
        int result = 0;

        result = ok_mult_short(x1, x2, &prod);
        printf("ok_mult_short\tx1: %d\tx2: %d\t\tprod: %d\t\tokay: %s\n", x1,x2, prod, (result==0) ? "yes" : "no");
        assert(result==0);
    }
    {
        short x1= SHRT_MAX;
        short x2= 1000;
        short prod = 0;
        int result = 0;

        result = ok_mult_short(x1, x2, &prod);
        printf("ok_mult_short\tx1: %d\tx2: %d\tprod: %d\t\tokay: %s\n", x1,x2, prod, (result==0) ? "yes" : "no");
        // not what expected!!
        //assert(result==1);
    }
     //Short2
    {
        short x1= 2000;
        short x2= 10;
        short prod = 0;
        int result = 0;

        result = ok_mult_short2(x1, x2, &prod);
        printf("ok_mult_short2\tx1: %d\tx2: %d\t\tprod: %d\t\tokay: %s\n", x1,x2, prod, (result==0) ? "yes" : "no");
        assert(result==0);
    }
    {
        short x1= SHRT_MAX;
        short x2= 1000;
        short prod = 0;
        int result = 0;

        result = ok_mult_short2(x1, x2, &prod);
        printf("ok_mult_short2\tx1: %d\tx2: %d\tprod: %d\t\tokay: %s\n", x1,x2, prod, (result==0) ? "yes" : "no");
        assert(result==1);
        
    }


    return EXIT_SUCCESS;
}

int ok_mult_int(int x, int y, int * dest){
    int result = 0;

    *dest = x*y;
    asm("seto %%dl;"
        "movzbl %%dl, %0;"
        : "=r" (result) // %0
        :
        : "%edx"
    );
    return result;
}

int ok_mult_short(short x, short y, short *dest){
    int result = 1;

    *dest = x*y;
    asm("seto %%dl;"
        "movzbl %%dl, %0;"
        : "=r" (result) // %0
        :
        : "%edx"
    );
    return result;
}
int ok_mult_short2(short x, short y, short *dest){
    int result = 2;

    asm("mov %2, %%ax;"
        "mov %3, %%bx;"
        "imul %%bx, %%ax;"
        "seto %%dl;"
        "mov %%ax, %1;"
        "movzbl %%dl, %0;"
        : "=r" (result) /* %0 */,"=r" (*dest) /* %1 */
        :"r" (x) /* %2 */, "r" (y) /* %3 */
        : "%edx", "%ebx", "edx"
    );
    return result;
}
