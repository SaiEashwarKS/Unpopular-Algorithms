
#ifndef LIST_H
#define LIST_H
#define MAXI 5
struct array_list{
	int key[MAXI];
	int next[MAXI];
	int freenext[MAXI];
	int head;
	int freehead;
	int temp;
};
typedef struct array_list list_t;
void init_list(list_t *ptr_list);
void insert_list(list_t *ptr_list, int elem);
void disp_list(const list_t *ptr_list);
void delete_list(list_t* ptr_list, int elem);
#endif
