#ifndef __MEM_INIT_H__
#define __MEM_INIT_H__

#include "serial.h"
#include "util.h"

#define SIZE_MMAP_TABLE 64

struct mmap_entry{
	uint32_t size;
	uint64_t addr;
	uint64_t len;
	uint32_t type;
}__attribute__((packed));
typedef struct mmap_entry mmap_entry;


void init_mem();


#endif
