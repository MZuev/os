#include "mem_init.h"

mmap_entry mmap_table[SIZE_MMAP_TABLE];
extern uint64_t multiboot_info;
uint32_t mmap_table_length;

void add_mmap_entry(mmap_entry *seg, mmap_entry ker) {
	if (!seg->len)
		return;
	uint64_t l_ker = ker.addr, r_ker = ker.addr + ker.len - 1,
		l_entry = seg->addr, r_entry = seg->addr + seg->len - 1;
	if (l_entry > r_ker || r_entry < l_ker) {
		mmap_table[mmap_table_length++] = *seg;
		return;
	}
	if (r_entry > r_ker) {
		mmap_entry tmp_seg = *seg;
		tmp_seg.addr = r_ker + 1;
		tmp_seg.len = r_entry - r_ker;
		mmap_table[mmap_table_length++] = tmp_seg;
	}
	if (l_entry < l_ker) {
		mmap_entry tmp_seg = *seg;
		tmp_seg.addr = l_entry;
		tmp_seg.len = l_ker - l_entry;
		mmap_table[mmap_table_length++] = tmp_seg;
	}
	return;
}

void init_mem() {
	extern char text_phys_begin[];
	extern char bss_phys_end[];

	mmap_entry kernel;
	kernel.addr = (uint64_t)text_phys_begin;
	kernel.len = (uint64_t)bss_phys_end - kernel.addr;
	kernel.type = 0;
	mmap_table[mmap_table_length++] = kernel;
	
	uint32_t *pmultiboot_info = (uint32_t*)multiboot_info;
	uint32_t mmap_size = *(pmultiboot_info + 11);
	char* mmap_addr = (char*)(uint64_t)*(pmultiboot_info + 12);
	uint64_t pos = 0;
	while (pos < mmap_size) {
		mmap_entry *seg = (void*)((uint64_t)(mmap_addr + pos));
		add_mmap_entry(seg, kernel);
		pos += seg->size + 4;
	}
	puts("All segments:\n");
	for (uint32_t i = 0; i < mmap_table_length; ++i) {
		mmap_entry seg = mmap_table[i];
		puts("Memory segment ");
		put_int(i);
		puts(": ");
		put_uint64(seg.addr, 16, 16);
		puts(" - ");
		put_uint64(seg.addr + seg.len - 1, 16, 16);
		puts(" len ");
		put_uint64(seg.len, 10, 0);
		puts(" type ");
		put_uint32(seg.type, 10, 0);
		putc('\n');
	}
	uint32_t cur_length = 0;
	for (uint32_t i = 0; i < mmap_table_length; ++i) {
		if (mmap_table[i].type != 1)
			continue;
		mmap_table[cur_length++] = mmap_table[i];
	}
	mmap_table_length = cur_length;
	puts("\nAvailable segments:\n");
	for (uint32_t i = 0; i < mmap_table_length; ++i) {
		mmap_entry seg = mmap_table[i];
		puts("Memory segment ");
		put_int(i);
		puts(": ");
		put_uint64(seg.addr, 16, 16);
		puts(" - ");
		put_uint64(seg.addr + seg.len - 1, 16, 16);
		puts(" len ");
		put_uint64(seg.len, 10, 0);
		puts(" type ");
		put_uint32(seg.type, 10, 0);
		putc('\n');
	}
}

