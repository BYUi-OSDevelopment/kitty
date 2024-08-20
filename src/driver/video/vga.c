//
// Created by AIDAN PRATT on 11/1/2023.
//
/*
 * Controls VGA text mode and graphics modes
 *
 */
#include <stdint.h>
#include "vga.h"
/*
 * Writes a string starting at 0,0
 */
void write_string(uint8_t color, char *string )
{
    write_string_at(color, string, 0,0);
}

/*
 * Write string at screen location.
 */
void write_string_at(uint8_t color, char *string, uint8_t x, uint8_t y) {
    uint8_t * video = (uint8_t *) 0xb8000 + (y * 160)  + (x * 2);
    while ( *string != 0 && video < (uint8_t *) 0xb8FA0) {
        *video = *string;
        string++;
        video++;
        *video = color;
        video++;
    }
}
/*
 * runtime function for computing the vga colors.
 */
uint8_t inline get_vga3_color(uint8_t fore, uint8_t back) {
    return ((back << 4) + fore);
}