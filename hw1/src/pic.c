#include <pic.h>


void setup_pic() {
	setup_master();
	setup_slave();

	disable_pic();
	disable_ints();
}

void setup_master() {
	out8(MASTER_COMMAND, bits2(0, 4));
	out8(MASTER_DATE, MASTER_DESC_BEGIN);
	out8(MASTER_DATE, bit(2));
	out8(MASTER_DATE, bit(0));
}

void setup_slave() {
	out8(SLAVE_COMMAND, bits2(0, 4));
	out8(SLAVE_DATE, SLAVE_DESC_BEGIN);
	out8(SLAVE_DATE, 2);
	out8(SLAVE_DATE, bit(0));
}

void disable_pic() {
	out8(MASTER_DATE, 0xFF);
	out8(SLAVE_DATE, 0xFF);
}

void enable_pic() {
	out8(MASTER_DATE, 0);
	out8(SLAVE_DATE, 0);
}
