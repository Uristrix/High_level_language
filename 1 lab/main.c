#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkNum(char *num)
{
    char *end;
    strtol(num, &end, 10);

    if(strcmp(end, "") == 0)
        return true;

    return false;
}

void error(){ printf("\nERROR!!! Bad format\nEnter -h(--help) to get help\n\n"); }

void printHelp()
{
    printf("-h(--help) to get help\n");
    printf("-t(--table) to get Table of a simple types\n");
    printf("-c(--calc) calculate expression\n");
    printf("-o(--oct) Convert to octal number system\n");
    printf("-x(--hex) Convert to hexadecimal number system\n");
}

void printInfo()
{
    printf("\t\t\tLAB1\n");
    printf("//////////////////////////////////////////////////////\n");
    printf("This program can:\n");
    printf("1)Display table of a simple types\n") ;
    printf("2)Calculate simple expression\n");
    printf("3)Convert to octal number system\n");
    printf("4)Convert to hexadecimal number system\n");
    printf("Enter -h(--help) to get help\n\n");
}

void printTable()
{
    printf("Int:\t%llu | Char:\t%llu\n", sizeof(int), sizeof(char));
    printf("Short:\t%llu | Long:\t%llu\n", sizeof(short), sizeof(long));
    printf("Float:\t%llu | Double:\t%llu\n", sizeof(float), sizeof(double));
    printf("Bool:\t%llu | Void:\t%llu\n\n", sizeof(bool), sizeof(void));
}

int main(int argc, char* argv[])
{
    if(argc < 2)
        printInfo();

    else if(argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
        printHelp();

    else if(argc == 2 && (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--table") == 0))
        printTable();

    else if(argc == 3 && (strcmp(argv[1], "-o") == 0 || strcmp(argv[1], "--oct") == 0) && checkNum(argv[2]))
        printf("%lo\n\n", strtol(argv[2], NULL, 10));

    else if(argc == 3 && (strcmp(argv[1], "-x") == 0 || strcmp(argv[1], "--hex") == 0) && checkNum(argv[2]))
        printf("%lx\n\n", strtol(argv[2], NULL, 10));

    else if((argc == 5 || argc == 6) && (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--calc") == 0))
    {
        bool check = (argc == 6);
        int res;

        if(checkNum(argv[2 + check]) && checkNum(argv[4 + check]))
        {
            if(strcmp(argv[3 + check], "+") == 0)
                res = atoi(argv[2 + check]) + atoi(argv[4 + check]);

            else if(strcmp(argv[3 + check], "-") == 0)
                res = atoi(argv[2 + check]) - atoi(argv[4 + check]);

            else if(strcmp(argv[3 + check], "*") == 0)
                res = atoi(argv[2 + check]) * atoi(argv[4 + check]);

            else if(strcmp(argv[3 + check], "/") == 0 && strcmp(argv[4 + check], "0") != 0 )
                res = atoi(argv[2 + check]) / atoi(argv[4 + check]);

            else{error(); return 0;}
        }
        else{error(); return 0;}

        if(check && (strcmp(argv[2], "-x") == 0 || strcmp(argv[2], "--hex") == 0))
            printf("%x\n\n", res);

        else if(check && (strcmp(argv[2], "-o") == 0 || strcmp(argv[2], "--oct") == 0))
            printf("%o\n\n", res);

        else
            printf("%i\n\n", res);
    }

    else error();

    return 0;
}