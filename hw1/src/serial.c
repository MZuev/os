#include <serial.h>

void setup_serial_port() {
	out8(SERIAL_PORT(3), bit(7));
	out8(SERIAL_PORT(0), 1);
	out8(SERIAL_PORT(1), 0);
	out8(SERIAL_PORT(3), bits2(0, 1));
	out8(SERIAL_PORT(1), 0);
	return;
}

void putc(char a) {
	while(!(in8(SERIAL_PORT(5)) & bit(5)));
	out8(SERIAL_PORT(0), a);
	return;
}
void put_int(int a) {
	if (!a) {
		putc('0');
		return;	
	}
	if (a < 0) {
		putc('-');
		a = -a;	
	}
	char buf[32];
	int cnt = 0;
	while (a) {
		buf[cnt++] = '0' + (a % 10);
		a /= 10;
	}
	while (cnt)
		putc(buf[--cnt]);
	return;
}

void puts(const char *s) {
	while (*s)
		putc(*(s++));
	return;
}
