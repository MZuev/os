#ifndef __PIT_H__
#define __PIT_H__

#include <util.h>
#include <ioport.h>
#include <serial.h>

#define COMMAND_PORT 0x43
#define NULL_PORT 0x40
#define IOTC_MODE 0
#define RG_MODE (2 << 1)

void setup_pit();

#endif
