//Zakeriya Muhumed || CS201 || Video Assigment 4

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// gcc -g -Wall -o front4 front4.c
// ./front4 < front4.c
// ./front4 front4.c
// ./front4 -f front4.c -n 3
// ./front4 -n6 front4.c
// ./front4 -n 6 <front4.c
// ./front4 front4.c -n3 front3.c -n 2 front1.c  ---> show the first 3 lines of each of those files 
// ./front4 -n2 front?.c

#define BUFFER_SIZE 1024
#define MAX_LINES 5

int main(int argc, char * argv[]){

    FILE *ifile = stdin;
    int line_count =0;
    int max_lines = MAX_LINES;
    char buf[BUFFER_SIZE]={'\0'};
    char *buf_ptr = NULL;
    char * file_name = NULL;

    {
        int opt = 0;
        while((opt = getopt(argc, argv, "n:h")) != -1){
            switch (opt){
            case 'n':
                // max_lines = atoi(optarg);
                // max_lines = strtol(optarg, NULL, 10);
                sscanf(optarg, "%d", &max_lines);
                if(max_lines <= 0){
                max_lines = MAX_LINES;
                }
                break;
            case 'h':
                printf("%s [-f file] [-n #] [-h]\n", argv[0]);
                exit(EXIT_SUCCESS);
                break;
            case '?':
                printf("*** eeek! skipping %c\n", optopt);
                break;
            default:
                exit(EXIT_FAILURE);
            }
        }
    }

    if(optind < argc){
        for(int j = optind; j < argc; j++){
            file_name = argv[j];
            ifile = fopen(file_name, "r");
            if(ifile == NULL){
                fprintf(stderr, " couldnt open file: %s\n", file_name);
            }
            else{
                line_count = 0;
                printf("==> %s <<==\n", file_name);

                buf_ptr = fgets(buf, BUFFER_SIZE, ifile);
                line_count++;
                while((line_count<=max_lines)&& (buf_ptr != NULL)){
                    printf("%s", buf);
                    buf_ptr = fgets(buf, BUFFER_SIZE, ifile);   
                    line_count++;
                }
                printf("\n");
                fclose(ifile);
            }
        }

    }
    else{
        buf_ptr = fgets(buf, BUFFER_SIZE, ifile);
        line_count++;
        while((line_count<=max_lines)&& (buf_ptr != NULL)){
            printf("%s", buf);
            buf_ptr = fgets(buf, BUFFER_SIZE, ifile);   
            line_count++;
        }
    }
    return EXIT_SUCCESS;
}