#ifndef LAB3
#define LAB3
#include <stdio.h>

struct elem {wchar_t c; int num1; float num2;};
typedef struct elem* pElem;

pElem init_struct(int size, char* str);

void table(FILE * file, pElem chars, int size);

void num_of_letters(FILE* file);

#endif