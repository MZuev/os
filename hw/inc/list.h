#ifndef __LIST_H__
#define __LIST_H__

struct list_node{
	struct list_node* next, * prev;
}__attribute__((packed));
typedef struct list_node list_node;

void add_next(list_node *, list_node *);

void add_prev(list_node *, list_node *);

void erase_cur(list_node *);

void erase_next(list_node *);

void erase_prev(list_node *);

char empty_list(list_node *);

#endif
