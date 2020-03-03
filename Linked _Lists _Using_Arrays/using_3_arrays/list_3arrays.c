#include "list.h"
#include<stdio.h>
void init_list(list_t* ptr_list)
{
	ptr_list -> head = -1;
	ptr_list -> freehead = 0;
	ptr_list -> temp = 0;
	for(int i = 0; i < MAXI - 1; ++i)
	{
		ptr_list -> freenext[i] = i + 1;
	}
	ptr_list -> freenext[MAXI - 1] = -1;
}

void insert_list(list_t* ptr_list, int elem)
{
	if(ptr_list -> freehead == -1)
	{
		printf("List is full\n");
		return;
	}
	int prev = -1;
	int pres = ptr_list -> head;
	ptr_list -> temp = ptr_list -> freehead;
	ptr_list -> key[ptr_list -> temp] = elem;
	while(pres != -1 && ptr_list->key[pres] < ptr_list->key[ptr_list -> temp])
	{
		prev = pres;
		pres = ptr_list -> next[pres];
	}
	if(prev != -1) //insert in middle or rear
	{
		ptr_list -> next[prev] = ptr_list -> temp;
		ptr_list -> next[ptr_list -> temp] = pres;
	}
	else //insert in beginning
	{
		ptr_list -> next[ptr_list -> temp] = pres;
		ptr_list -> head = ptr_list -> temp;
	}
	ptr_list->freehead = ptr_list->freenext[ptr_list -> freehead];
}

void disp_list(const list_t *ptr_list)
{
	int pres = ptr_list -> head;
	if(pres == -1)
	{
		printf("Empty list\n");
		return;
	}
	while(pres != -1)
	{
		printf("%d ", ptr_list -> key[pres]);
		pres = ptr_list -> next[pres];
	}
	printf("\n");
}
void delete_list(list_t* ptr_list, int elem)
{
	int prev = -1;
	int pres = ptr_list->head;
	if(pres == -1)
	{
		printf("Empty List \n");
		return;
	}
	while(ptr_list->key[pres] != elem && pres != -1)
	{
		prev = pres;
		pres = ptr_list->next[pres];
	}
	if(pres == -1)
	{
		printf("Element not found\n");
	}	
	else if(prev == -1) //delete in beginning
	{
		ptr_list->head = ptr_list->next[pres];
	}
	else //delete in middle or rear
	{
		ptr_list->next[prev] = ptr_list->next[pres];
	}
	ptr_list->freenext[pres] = ptr_list->freehead;
	ptr_list->freehead = pres;
}
