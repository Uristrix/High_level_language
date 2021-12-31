#include <stdio.h>
#include <stdlib.h>

int _global = 0;
static int _static;

int main()
{
	int _local = 0;

	printf("Text  : %p \n", (void*)main);
	printf("Data  : %p \n", (void*)&_global);
	printf("BSS   : %p \n", (void*)&_static);
	printf("Heap  : %p \n", malloc(64));
	printf("Stack : %p \n", (void*)&_local);

	return 0;
}