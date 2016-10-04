#include <desc.h>
#include <memory.h>
#include <util.h>
#include <serial.h>
#include <ints.h>

#define MASTER_COMMAND 0x20
#define MASTER_DATE 0x21

#define MASTER_DESC_BEGIN 240
#define MASTER_DESC_END 247

#define SLAVE_COMMAND 0xA0
#define SLAVE_DATE 0xA1

#define SLAVE_DESC_BEGIN 248
#define SLAVE_DESC_END 255

void setup_pic();

void setup_slave();

void setup_master();

void enable_pic();

void disable_pic();
