#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <stdint.h>
#include <ioport.h>
#include <util.h>

#define SERIAL_PORT_ADDR 0x3f8

#define SERIAL_PORT(n) (SERIAL_PORT_ADDR + n)

void setup_serial_port();

void putc(char);

void puts(const char *);

void put_int(int a);

void put_uint32(uint32_t, int, int);

void put_uint64(uint64_t, int, int);

#endif
