//Zakeriya Muhumed || CS201 || Lab 5

//Librays
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char * argv[]){

    long exp_bits = 8;
    long frac_bits = 23;
    double frac_add = 1.0;
    double exp_bias = 0.0;

    char line[300] = {0};
    char * ch = NULL;

    FILE * ifile = stdin;
    {

        int opt = 0;

        while((opt = getopt(argc, argv, "i:dhHbme:E:f:F:")) != - 1){
        switch (opt) {
            case 'i':
                ifile = fopen(optarg, "r");
                if (!ifile){
                    fprintf(stderr, " could not open file: %s\n", optarg);
                    return EXIT_FAILURE;
                }
                break;
            case 'd':
                exp_bits = 11;
                frac_bits = 52;
                break;
            case 'v':
                fprintf(stderr, " Error\n");
                break;
            case 'h':
                exp_bits = 5;
                frac_bits = 10;
                break;
            case 'H':
                printf("Usage: ./hex-2-float [OPTION ...]\n");
                printf("\t\t\tSettings default to single precision (float, 32-bits, 1-8-23)\n");
                printf("\t\t\tInput defaults to stdin if -i <file_name> is not used\n");
                printf("\t\t\tUnless otherwise specified, the bias follows IEEE 754 rules\n");
                printf("\t\t-i <file_name> specify the name of the input file\n");
                printf("\t\t-d   use settings for double precision (double, 64-bits, 1-11-52)\n");
                printf("\t\t-h   use settings for half precision (_Float16, 16-bits, 1-5-10)\n");
                printf("\t\t-b   use settings for half precision (bfloat16, 16-bits, 1-8-7)\n");
                printf("\t\t-m   use settings for quarter precision (minifloat, 8-bits, 1-4-3  bias -2)\n");
                printf("\t\t-e # set the number of bits to use for the exponent\n");
                printf("\t\t-E # set the value used for the exponent bias\n");
                printf("\t\t-f # set the number of bits to use for the fraction\n");
                printf("\t\t-F # set the value to add to the fraction (unstored fraction bits, normalized form)\n");
                printf("\t\t-B   read the input as binary. Spaces are okay between fields, but no trailing comments (eg 1 001 1101)\n");
                printf("\t\t-v   print the settings (to stderr) before reading input\n");
                printf("\t\t-H   display this most wonderful message and exit\n");
                return EXIT_SUCCESS;
            case 'b':
                exp_bits = 8;
                frac_bits = 7;
                break;
            case 'm':
                exp_bits = 4;
                frac_bits = 3;
                exp_bias = -2;
                break;
            case 'e':
                exp_bits = strtod(optarg, NULL);
                break;
            case 'E':
                exp_bias = strtod(optarg, NULL);
                break;
            case 'f':
                frac_bits = strtod(optarg, NULL);
                break;
            case 'F':
                frac_add = strtod(optarg, NULL);
                break;
            
            }
        }
    }

    ch = fgets(line, 300, ifile);

    while (ch != NULL){

        double ub_exp = 0.0;
        unsigned long exp = 0.0;   
        unsigned long long int plain_frac = 0;
        double frac = 0.0;
        double sign = 1.0;
        double norm_val = 0.0;
        double denorm_val = 0.0;
        unsigned long uv = 0x0;
        unsigned long mask = 0x1lu << (frac_bits + exp_bits);
        unsigned long exp_mask = 0x1lu;
        unsigned long frac_mask = 0x1lu;

        line[strlen(line) - 1] = '\0';
        sscanf(line, "%lx", &uv);

        sign = (uv & mask) ? -1.0 : 1.0;

        printf("%s\n", line);

        printf("\t%d ", (uv & mask) ? 1 : 0);
        for (int i = exp_bits; i > 0; i--) {
            mask >>= 1;
            printf("%d", (uv & mask) ? 1 : 0);
        }
        printf(" ");
        for (int i = frac_bits; i > 0; i--) {
            mask >>= 1;
            printf("%d", (uv & mask) ? 1 : 0);
        }
        printf("\n");

        printf("\ts ");
        for (int i = 0; i < exp_bits; i++) {
            printf("e");
        }
        printf(" ");
        for (int i = 0; i < frac_bits; i++) {
           printf("f"); 
        }
        printf("\n");

        for(int i = 0; i < exp_bits - 1; i++) {
            exp_mask <<= 1; 
            exp_mask |= 0x1lu;
        }
        exp_mask <<= frac_bits;

        frac_mask = (1ull << frac_bits) - 1;

        plain_frac = (double) (uv & frac_mask);

        for (int i = 1; i <= frac_bits; i++) {
            if ((plain_frac & (1ull << (frac_bits - i))) != 0) {
                frac += pow(2.0, -i);
            }
        }

        exp = (uv & exp_mask);
        if(exp_bias == 0){
            exp_bias = (unsigned long) pow(2, exp_bits-1) - 1;
        }

        ub_exp = exp >> frac_bits;
        norm_val = (frac_add + frac) * pow(2.0, ub_exp - exp_bias);
        denorm_val = frac * pow(2.0, 1 - exp_bias);


        if (exp == 0){
            if(sign == 1){
                printf("\tdenormalized value\n");
                printf("\tsign:\t\t%s\n", "positive");
                printf("\tbias:\t\t%-10.0lf\n", exp_bias);
                printf("\tunbiased exp:\t%-10.0lf\n", ub_exp);
                printf("\tE:\t\t%-10.0lf\n", 1 - exp_bias);
                printf("\tfrac:\t\t%-.20lf\n", frac);
                printf("\tM:\t\t%-.20lf\n", frac);
                printf("\tvalue:\t\t%-.20lf\n", denorm_val);
                printf("\tvalue:\t\t%-.20le\n\n", denorm_val);
            }
            else{
                printf("\tdenormalized value\n");
                printf("\tsign:\t\t%s\n", "negative");
                printf("\tbias:\t\t%-10.0lf\n", exp_bias);
                printf("\tunbiased exp:\t%-10.0lf\n", ub_exp);
                printf("\tE:\t\t%-10.0lf\n", 1 - exp_bias);
                printf("\tfrac:\t\t%-.20lf\n", frac);
                printf("\tM:\t\t%-.20lf\n", frac);
                printf("\tvalue:\t\t%-.20lf\n", -1 * denorm_val);
                printf("\tvalue:\t\t%-.20le\n\n", -1 * denorm_val);

            }
        }
        else if (exp == exp_mask){
            if (frac == 0){
                if(sign == 1){
                    printf("\tspecial value\n");
                    printf("\tpositive infinity\n\n");
                }
                else{
                    printf("\tspecial value\n");
                    printf("\tnegative infinity\n\n");
                }
            }
            else{
                printf("\tspecial value\n");
                printf("\tNaN\n\n");
            }
        }
        else{
            if(sign == 1){
                printf("\tnormalized value\n");
                printf("\tsign:\t\t%s\n", "positive");
                printf("\tbias:\t\t%-10.0lf\n", exp_bias);
                printf("\tunbiased exp:\t%-10.0lf\n", ub_exp);
                printf("\tE:\t\t%-10.0lf\n", ub_exp - exp_bias);
                printf("\tfrac:\t\t%-.20lf\n", frac);
                printf("\tM:\t\t%-.20lf\n", frac_add + frac);
                printf("\tvalue:\t\t%-.20lf\n", norm_val);
                printf("\tvalue:\t\t%-.20le\n\n", norm_val);
            }
           else{
                printf("\tnormalized value\n");
                printf("\tsign:\t\t%s\n", "negative");
                printf("\tbias:\t\t%-10.0lf\n", exp_bias);
                printf("\tunbiased exp:\t%-10.0lf\n", ub_exp);
                printf("\tE:\t\t%-10.0lf\n", ub_exp - exp_bias);
                printf("\tfrac:\t\t%-.20lf\n", frac);
                printf("\tM:\t\t%-.20lf\n", frac_add + frac);
                printf("\tvalue:\t\t%-.20lf\n", -1 * norm_val);
                printf("\tvalue:\t\t%-.20le\n\n", -1 * norm_val);
            }
        
        }
        ch = fgets(line, 300, ifile);
    }


    return EXIT_SUCCESS;
}