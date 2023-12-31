//
// Created by AIDAN on 11/7/2023.
//
#include <stdint.h>
#ifndef KITTY_VGA_H
#define KITTY_VGA_H

/*
 * VGA Mode 3
 */
#define VGA3_BLACK 0b00000000
#define VGA3_BLUE 0b00000001
#define VGA3_GREEN 0b00000010
#define VGA3_CYAN 0b00000011
#define VGA3_RED 0b00000100
#define VGA3_MAGENTA 0b00000101
#define VGA3_BROWN 0b00000110
#define VGA3_LIGHT_GRAY 0b00000111
#define VGA3_DARK_GRAY 0b00001000
#define VGA3_LIGHT_BLUE 0b00001001
#define VGA3_LIGHT_GREEN 0b00001010
#define VGA3_LIGHT_CYAN 0b00001011
#define VGA3_LIGHT_RED 0b00001100
#define VGA3_LIGHT_MAGENTA 0b00001101
#define VGA3_YELLOW 0b00001110
#define VGA3_WHITE 0b00001111

#define vga3_color(FORE, BACK) ((BACK << 4) + FORE) // for some reason this only works in 32 bit, i am going to lose my mind if another inconsistency like this pops up one more time

void write_string(uint8_t color, const char *string );

#endif //KITTY_VGA_H

