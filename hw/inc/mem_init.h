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

struct mboot_header{
	uint32_t MB_HEADER_MAGIC;
	uint32_t MB_HEADER_FLAGS;
	uint32_t MB_HEADER_CKSUM;
	uint32_t multiboot_header;
	uint32_t text_phys_begin;
	uint32_t data_phys_end;
	uint32_t bss_phys_end;
	uint32_t start32;
}__attribute__((packed));
typedef struct mboot_header mboot_header;

void init_mem();

void print_mem();

#endif
