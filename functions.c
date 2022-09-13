#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>

int digitValidate(char * string) {
    for (int i = 0; i < strlen(string); ++i) {
        if (!isdigit(string[i])) {
            if ('.' == string[i]) {
                continue;
            } else
                return 0;
        }
    }
    return 1;
}

int validate(int argc, char * argv[], char input[], char output[], float * min_price, int * min_year, int * flag){
    int opt;
    while((opt = getopt(argc,argv,":bi:o:d:p: :h"))!= -1){
        switch (opt) {
            case 'i':
                strcpy(input,optarg);
                break;
            case 'o':
                strcpy(output,optarg);
                break;
            case 'd':
                if(digitValidate(optarg))
                    *min_year = atoi(optarg);
                else{
                    printf("Invalid argument for %c\n",optopt);
                    exit(0);
                }
                break;
            case 'p':
                if(digitValidate(optarg))
                    *min_price = atof(optarg);
                else{
                    printf("Invalid argument for %c\n",optopt);
                    exit(0);
                }
                break;
            case 'b':
                *flag = 1;
                break;
            case 'h':
                printf("-i: input file including extension\n"
                       "-o: output file including extension\n"
                       "-d: game start year, must be a number\n"
                       "-p: minimum game price, must be in dollars\n"
                       "-b: details flag (show additional information on console)\n"
                       "-h: help\n");
                exit(0);
                break;
            case '?':
                printf("Unknown option: %c\n",optopt);
                break;
            case ':':
                printf("Missing arg for %c\n",optopt);
        }
    }
    if(*min_year == -1)
        return 0;
    return 1;
}