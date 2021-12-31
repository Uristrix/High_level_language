#include "lab3.h"
#include <string.h>
#include <malloc.h>

int main(int argc, char* argv[])
{
    FILE* file = fopen(argv[1], "r");

    if ((argc == 3) && (strcmp(argv[2], "-w") == 0 || strcmp(argv[2], "--word") == 0))
        num_of_letters(file);

    else if(((argc == 3) && (strcmp(argv[2], "--en") == 0)) ||
            ((argc == 4) && (strcmp(argv[2], "--en") == 0) && strcmp(argv[3], "--ir") == 0))
    {
        int size;
        if (argc == 4) size = 26; else size = 52;
        pElem chars = init_struct(size, argv[2]);
        table(file, chars, size);
        free(chars);
    }
    else if(((argc == 3) && (strcmp(argv[2], "--ru") == 0)) ||
            ((argc == 4) && (strcmp(argv[2], "--ru") == 0) && strcmp(argv[3], "--ir") == 0))
    {
        int size;
        if (argc == 4) size = 32; else size = 64;
        pElem chars = init_struct(size, argv[2]);
        table(file, chars, size);
        free(chars);
    }
    else if((argc == 2) || (argc == 3) && (strcmp(argv[2], "--all") == 0))
    {
        pElem chars = init_struct(256, "--all");
        table(file, chars, 256);
        free(chars);
    }
    else printf("\nError format!!!\n");

    fclose(file);
    return 0;
}