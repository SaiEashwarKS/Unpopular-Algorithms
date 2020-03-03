#include <stdio.h>
// avoid the problem of multiple inclusion at compile time
#include "list.h"
#include "list.h"
#include <stdlib.h>

int main()
{

	list_t l;
	init_list(&l);
	int a[] = {25, 15, 35, 5, 45};
	int n = 5;
	while(1)
	{
		printf("\nEnter your choice\n");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		int ch, key;
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("\nEnter the element to be inserted\n");
					scanf("%d", &key);
					insert_list(&l, key);
					break;
			case 2: printf("\nEnter the element to be deleted\n");
					scanf("%d", &key);
					delete_list(&l, key);
					break;
			case 3: disp_list(&l);
					break;
			case 4: exit(1);
		}
	}
	
}
