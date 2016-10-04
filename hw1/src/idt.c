#include <idt.h>

static idt_desc idt[IDT_SIZE];
extern uint64_t inter_hand[];


void init_rec(int i, uint64_t pos) {
	idt[i].off0 = get_bit(pos, 0, 15);
	idt[i].ss = KERNEL_CS;
	idt[i].atr = bits4(9, 10, 11, 15);
	idt[i].off1 = get_bit(pos, 16, 31);
	idt[i].off2 = get_bit(pos, 32, 63);
	idt[i].res = 0;
	return;
}

void init_idt() {
	for (int i = 0; i < IDT_SIZE; ++i)
		init_rec(i, inter_hand[i]);
	struct desc_table_ptr idtr;
	idtr.addr = (uint64_t)idt;
	idtr.size = sizeof(idt) - 1;
	write_idtr(&idtr);
	return;
}

void c_hand(uint64_t numb) {
	puts("It's interrupt number ");
	put_int(numb);
	putc('\n');
	if (numb >= MASTER_DESC_BEGIN && numb <= MASTER_DESC_END)
		out8(MASTER_COMMAND, bit(5));
	if (numb >= SLAVE_DESC_BEGIN && numb <= SLAVE_DESC_END)
		out8(MASTER_COMMAND, bit(5)), out8(SLAVE_COMMAND, bit(5));
	return;
}
