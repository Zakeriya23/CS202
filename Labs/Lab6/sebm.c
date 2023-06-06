//Zakeriya Muhumed || CS201 || Lab 6

//Librays
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <math.h>

void print_address_bits_distribution(int t, int s, int b);

void print_address_bits_distribution(int t, int s, int b) {
    printf("\n\tAddress bits distribution\n");
    printf("\t");
    for (int i = 0; i < t; i++) {
        printf("t");
    }
    
    if (s > 0) printf(" ");
    for (int i = 0; i < s; i++) {
        printf("s");
    }
    printf(" ");
    for (int i = 0; i < b; i++) {
        printf("o");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int S = 0;
    int E = 0;
    int B = 0;
    int m = 0;
    int opt;
    //int v;
    int t;
    int s;
    char *cache_type;

    while ((opt = getopt(argc, argv, "S:E:B:m:vh")) != -1) {
        switch (opt) {
            case 'S':
                S = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'B':
                B = atoi(optarg);
                break;
            case 'm':
                m = atoi(optarg);
                break;
            case 'v':
                //v = 1;
                break;
            case 'h':
            default:
               // printf("Invalid command line option.\n");
                printf("Usage: sebm S:E:B:m:vh\n"
                       "  -S #    number of sets in cache (required > 1)\n"
                       "  -E #    number of blocks in set (required > 1)\n"
                       "  -B #    number of bytes in block (required > 1)\n"
                       "  -m #    number of bits in address (required > 1)\n"
                       "  -h      helpful text\n"
                       "  -v      verbose\n");
                exit(EXIT_FAILURE);
        }
    }

    if (S == 0 || E == 0 || B == 0 || m == 0) {
        printf("Configuration option missing.\n");
        printf("Usage: sebm S:E:B:m:vh\n"
                "  -S #    number of sets in cache (required > 1)\n"
                "  -E #    number of blocks in set (required > 1)\n"
                "  -B #    number of bytes in block (required > 1)\n"
                "  -m #    number of bits in address (required > 1)\n"
                "  -h      helpful text\n"
                "  -v      verbose\n");
        exit(EXIT_FAILURE);
    }

    s = log2(S); // Assign value to 's' here
    t = m - (s + log2(B)); // Assign value to 't' here

    if (t < 1) {
        printf("Configuration invalid.\n");
        printf("Usage: sebm S:E:B:m:vh\n"
                "  -S #    number of sets in cache (required > 1)\n"
                "  -E #    number of blocks in set (required > 1)\n"
                "  -B #    number of bytes in block (required > 1)\n"
                "  -m #    number of bits in address (required > 1)\n"
                "  -h      helpful text\n"
                "  -v      verbose\n");;
        exit(3);
    }

    printf("Given a cache of (S,E,B,m) = (%d,%d,%d,%d)\n", S, E, B, m);
    printf("\t\t (s,t,b,m) = (%d,%d,%d,%d)\n", s, t, (int)log2(B), m);
    
    if (S == 1)
        cache_type = "Fully associative cache";
    else if (E == 1)
        cache_type = "Direct mapped cache";
    else
        cache_type = "4-way associative cache";

    printf("\t\t %s\n", cache_type);

    printf("\tHow many bits are in the address? m = %d\n", m);
    printf("\tHow many bytes are in a block? B = %d\n", B);
    printf("\tHow many bits are required for the block offset? b = %d\n", (int)log2(B));
    printf("\tHow many sets are in the cache? S = %d\n", S);
    printf("\tHow many bits are required for the set selector? s = %d\n", s);
    printf("\tHow many blocks are in a set? E = %d\n", E);
    printf("\tHow many bits are required for the block selector? 0\n");
    printf("\tHow many bits are in the tag? t = %d\n", t);
    print_address_bits_distribution(t, s, (int)log2(B));
    printf("Total bytes in cache: %d\n", S * E * B);

    return 0;
}