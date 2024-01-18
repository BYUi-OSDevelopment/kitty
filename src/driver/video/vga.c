//
// Created by AIDAN PRATT on 11/1/2023.
//
/*
 * Controls VGA text mode and graphics modes
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include "vga.h"
/*
 * Writes a string starting at 0,0
 */
void write_string(uint8_t color, char *string )
{
    uint8_t * video;

    video = (uint8_t *) 0xb8000;

    do {
        *video = *string;
        string++;
        video++;
        *video = color;
        video++;
    } while ( *string != 0 && video < 0xb87d0);

}

/*
 * Write string at screen location
 */
void write_string_at(unsigned char color, char *string, int x, int y) {

}
uint8_t inline get_vga3_color(uint8_t fore, uint8_t back) {
    return ((back << 4) + fore);
}