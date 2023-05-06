//Zakeriya Muhumed || PSU CS201 || Lab 2 || Char in octal, decimal, hex
#include <stdio.h>
#include <string.h>

#define STRLEN 500
int main(void){
    int choice = 0;
    char *part;
    char p[STRLEN] = {" "};
    char str[STRLEN] = {'\0'};

	fgets(str, STRLEN, stdin);
	sscanf(str,"%d", &choice);
	
    switch (choice){
    case 8:
        printf("octal input\n");
		while(fgets(str, STRLEN, stdin) != NULL) 	
		{
			part = strtok(str, p);
			for(int i = 0;part != NULL;++i)
			{	
				sscanf(part, "%o", &choice);
				if(choice == 0)
				{
					break;
				}
				printf("%c" ,choice); 
				part = strtok(NULL, p);
			}
			printf("\n");
        }
        break;
    case 10:
        printf("decimal input\n");
		while(fgets(str, STRLEN, stdin) != NULL) 	
		{
			part = strtok(str, p);
			for(int i = 0;part != NULL; ++i)
			{
				sscanf(part, "%d", &choice);
				if(choice== 0)
				{
					break;
				}
				printf("%c" , choice); 
				part = strtok(NULL, p);
			}
			printf("\n");
		}
        break;
    case 16:
      	printf("hex input\n");
		while(fgets(str, STRLEN, stdin) != NULL) 	
		{
			part = strtok(str, p);
			for(int i = 0;part != NULL;++i)
			{
				sscanf(part, "%x", &choice);
				if(choice == 0)
				{
					break;
				}
				printf("%c" ,choice); 
				part = strtok(NULL, p);
			}
			printf("\n");
		}			
    }
}
