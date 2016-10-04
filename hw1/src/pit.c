#include <pit.h>

void setup_pit() {
	out8(COMMAND_PORT, RG_MODE | bits2(4, 5));
	out8(NULL_PORT, 0xFF);
	out8(NULL_PORT, 0xFF);
	return;
}
