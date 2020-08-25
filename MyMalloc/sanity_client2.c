#include <stdio.h>
#include "assignment_1.h"
void main()
{
    //allocate(200);
    /*char *a = (char*)mymalloc(10*sizeof(char));
    display_mem_map();
    printf("\n");
    myfree(a);
    display_mem_map();
    printf("\n");
    char *b = (char*)mymalloc(10*sizeof(char));
    char *c = (char*)mymalloc(10*sizeof(char));
    display_mem_map();
    printf("\n");
    myfree(b);
    myfree(c);
    display_mem_map();
    printf("\n");
    char *d = (char*)mymalloc(30*sizeof(char));
    char *e = (char*)mymalloc(70*sizeof(char));
    display_mem_map();
    printf("\n");
    char *f = (char*)mymalloc(38*sizeof(char));
    display_mem_map();
    printf("\n");*/

    allocate(145);
    char *a = (char*)mymalloc(10*sizeof(char));
    char *b = (char*)mymalloc(11*sizeof(char));
    char *c = (char*)mymalloc(12*sizeof(char));
    char *d = (char*)mymalloc(13*sizeof(char));
    char *e = (char*)mymalloc(14*sizeof(char));
    display_mem_map();
    printf("\n");
    //myfree(a);
    myfree(b);
    myfree(d);
    display_mem_map();
    printf("\n");
    char *f = (char*)mymalloc(5*sizeof(char));
    display_mem_map();
    printf("\n");
    /*allocate(200);
    display_mem_map();
    printf("\n");
    char *a = (char*)mymalloc(20*sizeof(char));
    display_mem_map();
    printf("\n");
    char *b = (char*)mymalloc(10*sizeof(char));
    display_mem_map();
    printf("\n");*/
}