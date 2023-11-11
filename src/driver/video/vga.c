//
// Created by AIDAN PRATT on 11/1/2023.
//
/*
 * Controls VGA text mode and graphics modes
 *
 */
#include <stdint.h>
#include "vga.h"

void write_string(uint8_t color, const char *string )
{
#if Bits == 32
    uint8_t *video = (uint8_t *) 0xB8000;
#elif Bits == 64
    uint8_t *video = (uint8_t *) 0xB7FFE;
#endif
    do {
        *video = *string;
        string++;
        video++;
        *video = color;
        video++;
    } while ( *string != 0 );
}