//Zakeriya Muhumed || CS201 || Lab 5

//Librays
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define BUFFER_SIZE 1024
#define MAX_LINES 5

int line_count = 0;
int max_lines = MAX_LINES;
float f_val = 0;
double value = 0;
char line[300] = {0};
char * token = NULL;
char * ch = NULL;
int decision = 0;
float flt = 0;
double float_input = 0;
unsigned long int double_hex = 0;
unsigned int flt_hex = 0;
char * buf_ptr = NULL;
char * file_name = NULL;

static void float_convert(char *);
static void double_convert(char *);

static void float_convert(char * input){
    sscanf(input, "%f", &f_val);

    flt_hex = *(unsigned long int*)&f_val;
    printf("%-40s\t%.10e\t%.10f\t0x%08x\n", input, f_val, f_val, flt_hex);
}

static void double_convert(char * input){
    sscanf(input, "%lf", &value);
    double_hex = *(unsigned long int*)&value;
    printf("%-40s\t%.16le\t%.16lf\t0x%016lx\n", input, value, value, double_hex);
}


int main (int argc, char *argv[]){
    FILE * ifile = stdin;

    {
        int opt = 0;

        while((opt = getopt(argc, argv, "fdH")) != - 1){
        switch (opt) {
                case 'f':
                    break;
                case 'd':
                    decision = 1;
                    break; 
                case 'H': 
                   printf("Usage: %s\n", argv[0]);
                   printf("\t-f  convert the input into floats for hex output (this is the default)\n");
                   printf("\t-d  convert the input into doubles for hex output\n");
                   printf("\t-H  display this help message and exit\n");
                   exit(EXIT_SUCCESS);
                   break;
                case '?':
                   printf("*** eeeek! skipping %c\n", optopt);
                   break;
                default:
                   break;
            }
                
        }
        
    }

    ch = fgets(line, 300, stdin);
    while(ch != NULL){
        if(decision == 1){
            line[strlen(line) - 1] = '\0';
            token = strtok(line, "\t");
            double_convert(token);
        }
        else{
            line[strlen(line) - 1] = '\0';
            token = strtok(line, "\t");
            float_convert(token);
        }
        ch = fgets(line, 300, stdin);
    }

    
    if(file_name != NULL){
        fclose(ifile);
    }

    return EXIT_SUCCESS;
} 