#ifndef __IDT_H__
#define __IDT_H__

#include <desc.h>
#include <memory.h>
#include <util.h>
#include <serial.h>
#include <pic.h>

#define IDT_SIZE 256

struct idt_desc {
    uint16_t off0;
    uint16_t ss;
    uint16_t atr;
    uint16_t off1;
    uint32_t off2;
    uint32_t res;
} __attribute__((packed));
typedef struct idt_desc idt_desc;

void init_rec(int, uint64_t);

void init_idt();

void c_hand(uint64_t);

#endif
