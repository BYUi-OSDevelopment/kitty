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

void write_string(uint8_t color, uint8_t *string )
{
    uint8_t * video;
    uint8_t * vid_col;

    video = (uint8_t *) 0xb8000;
    vid_col = (uint8_t *) 0xb8001;

    *video = 'h';
    *vid_col = color;
    //do {
    //    *video = *string;
    //    string++;
    //    video++;
    //    *video = color;
    //    video++;
    //} while ( *string != 0 && string < 0xb87d0);

}

uint8_t inline get_vga3_color(uint8_t fore, uint8_t back) {
    return ((back << 4) + fore);
}