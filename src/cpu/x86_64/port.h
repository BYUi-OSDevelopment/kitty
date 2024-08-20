//
// Created by AIDAN on 8/19/2024.
//

#include <stdint.h>
#ifndef KITTY_PORT_H
#define KITTY_PORT_H

static inline void port_out_byte(uint16_t port, uint8_t value)
{
    asm volatile ( "outb %b0, %w1" : : "a"(value), "Nd"(port) : "memory");
}

static inline uint8_t port_in_byte(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %w1, %b0" : "=a"(ret) : "Nd"(port) : "memory");
    return ret;
}

#endif //KITTY_PORT_H
