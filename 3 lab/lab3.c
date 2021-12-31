#include "lab3.h"
#include <string.h>
#include <ctype.h>
//#include <locale.h>
#include <malloc.h>
#include <math.h>
#define SIZE 256

pElem init_struct(int size, char* str)
{
    pElem chars = (pElem)malloc(sizeof(struct elem) * size);
    for(int i = 0; i < size; i++)
    {
        if(strcmp(str, "--en") == 0 && (size == 26 || size == 52))
        {
            if(i < 26) chars[i].c = (wchar_t)(65 + i);
            else chars[i].c = (wchar_t)(97 + i - 26);
        }
        else if(strcmp(str, "--ru") == 0 && (size == 32 || size == 64))
        {
            if(i < 32) chars[i].c = (wchar_t)(192 + i);
            else chars[i].c = (wchar_t)(224 + i - 32);
        }
        else if(strcmp(str, "--all") == 0)
            chars[i].c = (wchar_t)(i);

        chars[i].num1 = chars[i].num2 = 0;
    }
    return chars;
}

void table(FILE * file, pElem chars, int size)
{
    int all_char = 0;
    for(wchar_t c = fgetwc(file); c != WEOF; c = fgetwc(file), all_char++)
        for(int i = 0; i < size; i++)
        {
            if((size == 26) && abs((int)c - (int)chars[i].c) == 26) chars[i].num1++;
            else if((size == 32) && abs((int)c - (int)chars[i].c) == 32) chars[i].num1++;
            else if(c == chars[i].c) chars[i].num1++;
        }

    for(int i = 0; i < size; i++)
        chars[i].num2 = (float)chars[i].num1 / (float) all_char;

    wprintf(L"char\tnum\t\tfreq\n");
    for(int i = 0; i < size; i++)
        wprintf(L"%c\t\t%li\t\t%.4lf%\n", chars[i].c, chars[i].num1, chars[i].num2);
}

void num_of_letters(FILE* file)
{
    wchar_t temp[SIZE];
    int num_of_letters = 0;

    while(fgetws(temp, SIZE, file) != NULL)
        for(wchar_t* i = wcstok(temp, L" \t\n"); i != NULL; i = wcstok(NULL, L" \t\n"), num_of_letters++);

    wprintf(L"Number of letters: %i", num_of_letters);
}