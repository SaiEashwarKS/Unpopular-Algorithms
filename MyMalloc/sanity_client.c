#include <stdio.h>
#include "assignment_1.h"
void main()
{
    allocate(200);
    char *a = (char *)mymalloc(30 * sizeof(char));
	display_mem_map();
	printf("\n");
	char *b = (char *)mymalloc(40 * sizeof(char));
	display_mem_map();
	printf("\n");
	char *c = (char *)mymalloc(30 * sizeof(char));
	display_mem_map();
	printf("\n");
	myfree(a);
	display_mem_map();
	printf("\n");
	myfree(b);
	display_mem_map();
	printf("\n");
    myfree(c);
	display_mem_map();
	printf("\n");
	/*allocate(78);
	char* a = (char*)mymalloc(10*sizeof(char));
	char* b = (char*)mymalloc(10*sizeof(char));
	char* c = (char*)mymalloc(10*sizeof(char));
	display_mem_map();
	printf("\n");

	myfree(b);
	display_mem_map();
	printf("\n");

	b = (char*)mymalloc(5 * sizeof(char));
	display_mem_map();
	printf("\n");*/
}
