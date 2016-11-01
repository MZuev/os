#ifndef __BUDDY_H__
#define __BUDDY_H__

#include "list.h"
#include "mem_init.h"
#include <stdint.h>

#define MAX_ORD 64
#define BUDDY_PAGE_SIZE 4096ULL


struct buddy_desc{
	list_node node;
	uint64_t num;
	uint32_t is_free;
	uint32_t ord;
}__attribute__((packed));
typedef struct buddy_desc buddy_desc;

void init_buddy();

void init_entry(mmap_entry);

void print_list(int);

void print_some_buddy(int);

uint64_t get_max_reg(mmap_entry);

uint64_t alloc(uint64_t);

void free(uint64_t);

#endif
