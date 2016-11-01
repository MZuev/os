static void qemu_gdb_hang(void)
{
#ifdef DEBUG
	static volatile int wait = 1;

	while (wait);
#endif
}

#include <desc.h>
#include <ints.h>
#include <serial.h>
#include <pic.h>
#include <idt.h>
#include <pit.h>
#include <pic.h>
#include <memory.h>
#include <mem_init.h>
#include <buddy.h>

extern int max_heads;

void init_all() {
	setup_serial_port();
	init_idt();
	setup_pic();
	init_mem();
	init_buddy();
}

void start_pit() {
	enable_pic();
	enable_ints();
	setup_pit();	
}

void test_buddy() {
	print_some_buddy(max_heads);
	uint64_t a = alloc(BUDDY_PAGE_SIZE);
	uint64_t b = alloc(BUDDY_PAGE_SIZE);
	uint64_t c = alloc(BUDDY_PAGE_SIZE);
	uint64_t d = alloc(BUDDY_PAGE_SIZE << 1);
	uint64_t e = alloc(BUDDY_PAGE_SIZE << 1);
	uint64_t f = alloc(BUDDY_PAGE_SIZE << 1);
	uint64_t g = alloc(BUDDY_PAGE_SIZE);
	put_uint64(a, 16, 16);
	putc('\n');
	put_uint64(b, 16, 16);
	putc('\n');
	put_uint64(c, 16, 16);
	putc('\n');
	put_uint64(d, 16, 16);
	putc('\n');
	put_uint64(e, 16, 16);
	putc('\n');
	put_uint64(f, 16, 16);
	putc('\n');	
	put_uint64(g, 16, 16);
	putc('\n');

	print_some_buddy(2);

	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
	free(g);
	putc('\n');
	
	print_some_buddy(2);
	return;
}

void main(void)
{	
	qemu_gdb_hang();

	init_all();
	
	test_buddy();

	

	while (1);
}
