#include <stdio.h>
#include <stdlib.h>
#include "assignment_1.h"

typedef struct book
{
	int isfree;   //flag to check if block is free or allocated
	int size;	 //size of the block excluding the book
	long int ptr; //contains address of the block
} book;

char *p; //global pointer that points to the memory (character array)
int size;
void allocate(int n)
{
	p = (char *)malloc(n * sizeof(char));
	size = n;
	book *firstbook = (book *)(p);
	firstbook->isfree = 1;	//initially the block is free
	firstbook->size = n - sizeof(book);
	firstbook->ptr = (long int)(p + sizeof(book)); //address of the first block
}

void print_book()
{
	printf("%ld", sizeof(book));
}

void *mymalloc(int Size)
{
	int worst_block = 0; //the block with worst fit for the requested size
						 //worst block should have the size of the biggest free block whose size is greater than the requested size
	int i = 0;
	int index = -1; 	 //index to point to the book of the block of worst fit
	book *b;
	void *ptr; 			 //the pointer which is returned
	while (i < size)
	{
		b = (book *)(p + i);
		if (b->isfree != 1) //the book points to a block which is allocated
		{
			i = i + sizeof(book) + b->size; //to go to the next book
		}
		else //the book points to a free block
		{
			if (b->size >= Size && b->size > worst_block) //to update the worst block
			{
				worst_block = b->size;
				index = i;
			}
			i = i + sizeof(book) + b->size; //location of next book
		}
	}
	if (index == -1) //block with required space not found
	{
		return NULL;
	}
	b = (book *)(p + index);
	ptr = (void *)(p + index + sizeof(book));
	b->isfree = 0;			 //mark the block as allocated
	int free_size = b->size; //size of the free block before allocating
	b->size = Size;			 //size of the block pointed by the book changes after allocation
	b->ptr = (long int)ptr;
	if (free_size - Size <= sizeof(book)) //if the remaining block has size too less to even store the book
	{
		b->size = free_size; //add the remaining small free space to the previous book itself
	}
	else
	{
		book *new_book = (book *)(p + index + sizeof(book) + Size); //creating new book for the new free block
		new_book->size = free_size - Size - sizeof(book);
		new_book->isfree = 1;
	}

	return ptr;
}

void display_mem_map()
{
	int i = 0;
	book *b;
	while (i < size)
	{
		b = (book *)(p + i);
		printf("%d\t%ld\tbook\n", i, sizeof(book)); //info of books
		if (b->isfree)
		{
			printf("%ld\t%d\tfree\n", i + sizeof(book), b->size); //info of free blocks
		}
		else
		{
			printf("%ld\t%d\tallocated\n", i + sizeof(book), b->size); //info of allocated blocks
		}
		i = i + sizeof(book) + b->size; //index of next book
	}
}

void myfree(void *b)
{
	int i = 0;
	book *prev = NULL; //book to the left of the book containing information of b
	book *pres = NULL; //book containing information of b
	book *next = NULL; //book to the right of pres
	do
	{
		prev = pres;
		pres = (book *)(p + i);
		if (i + sizeof(book) + pres->size < size)
		{
			next = (book *)(p + i + sizeof(book) + pres->size);
		}
		else
		{
			next = NULL;
		}
		i = i + sizeof(book) + pres->size;
	} while (i < size && pres->ptr != (long int)b); //iterate until we get matching book
	pres->isfree = 1; //the block becomes free
	if (prev == NULL) //freeing the first block
	{
		if (next != NULL && next->isfree == 1) //should merge the pres and next blocks
		{
			pres->size = pres->size + sizeof(book) + next->size;
		}
	}
	else if (next == NULL) //freeing the last block
	{
		if (prev->isfree == 1) //should merge the prev and pres blocks
		{
			prev->size = prev->size + sizeof(book) + pres->size;
		}
	}
	else //freeing a block in the middle
	{
		if (prev->isfree && next->isfree) //should merge all the three blocks
		{
			prev->size = prev->size + 2 * sizeof(book) + pres->size + next->size;
		}
		else if (next->isfree) //should merge the pres and next blocks
		{
			pres->size = pres->size + sizeof(book) + next->size;
		}
		else if (prev->isfree) //should merge the prev and pres blocks
		{
			prev->size = prev->size + sizeof(book) + pres->size;
		}
	}
}