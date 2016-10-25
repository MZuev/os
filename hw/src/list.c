#include "list.h"

void add_next(list_node *cur_node, list_node *new_node) {
	new_node->next = cur_node->next;
	new_node->prev = cur_node;
	new_node->prev->next = new_node;
	new_node->next->prev = new_node;
	return;
}

void add_prev(list_node *cur_node, list_node *new_node) {
	add_next(cur_node->prev, new_node);
}

void erase_cur(list_node *cur_node) {
	cur_node->next->prev = cur_node->prev;
	cur_node->prev->next = cur_node->next;
	cur_node->prev = cur_node->next = cur_node;
	return;
}

void erase_next(list_node *cur_node) {
	erase_cur(cur_node->next);
}

void erase_prev(list_node *cur_node) {
	erase_cur(cur_node->prev);
}

char empty_list(list_node *cur_node) {
	return cur_node == cur_node->next && cur_node == cur_node->prev;
}
