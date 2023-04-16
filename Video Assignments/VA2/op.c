//Zakeriya Muhumed || CS201 || Assignemnt Video 2
#include <stdio.h>

// gcc -Wall -g -o op op.c
// ./op

int main(void){

    {//strings 
    char *str1 = "hello1"; //7 bytes 
    char str2[] = "hello2"; // 7bytes 
    char str3[20]= "hello3"; //20bytes 

    puts(str1);
    printf(">>%s<< %%s\n", str1);
    printf(">>%15s<< %%15s\n", str2);
    printf(">>%-15s<< %%-15s\n", str3);
    printf(">>%3s<< small field %%3s\n", str1);

    }

    {//integer 
    char ssi = 65; //1 bytes 
    int i = 10;   // 4 bytes 
    short si = 7; //2bytes
    long li = 117; //8 bytes 
    long long lli = 1117; // 8 btyes
    unsigned ui = 5; //6 btyes 

    printf("%d int %%d\n", i);
    printf("%hd short %%hd\n", si);
    printf("%hhd char as int %%hhd\n", ssi);
    printf("%ld long %%ld\n", li);
    printf("%lld long long %%lld\n", lli);
    
    printf("%c char as char %%c\n", ssi);

    printf("%u unsigned %%u\n",ui);

    printf(">>%10d< %%10d\n ", i);
    printf(">>%-10d<<  %%-10d\n", i);
    printf(">>%010d <<  %%010d\n", i);

    printf(">>%#o<< octal %%#0\n ", i);
    printf(">>%#x<< hex %%#x\n ", i);
    printf(">>%#X<< octal %%#X\n ", i);


    printf(">>%p<< pointer %%p\n",(void *) &i);

    }

    {//Float 

    float f = 3.14;  // 4 bytes 
    double d = 6.24; // 8btyes 
    long double ld = 12.56; // 14 bytes 

    printf("%f float %%f\n", f);
    printf("%lf double %%lf\n", d);
    printf("%Lf long double  %%Lf\n", ld);

    printf(">>%8.3f<< float %%8.3f\n", f);
    printf(">>%08.3f<< float %%08.3f\n", f);
    printf(">>%-8.3f<< float %%-8.3f\n", f);
    printf(">>%+-8.3f<< float %%+-8.3f\n", f);

    printf(">>%14.5e<< float %%14.5e\n", f*100);




    }

    return 0;
}






