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

void init_all() {
	setup_serial_port();
	init_idt();
	setup_pic();
}

void start_pit() {
	enable_pic();
	enable_ints();
	setup_pit();	
}

void main(void)
{	
	qemu_gdb_hang();

	init_all();

	puts("Hello\n");
	
	__asm__ volatile("int $123");

	start_pit();

	while (1);
}
