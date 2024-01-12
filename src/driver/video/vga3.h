//
// VGA3.H
//
// Created by AIDAN PRATT on 11/7/2023.
// Modified by BRADY MCDERMOTT on 1/11/2024.
//
#include <stdint.h>
#ifndef KITTY_VGA3_H
#define KITTY_VGA3_H

/* Structures */
typedef struct vga3char {
	uint8_t character;
	uint8_t vga3_color;
} vga3char;

/* Video memory addresses */
#define VID_MEM_START 0xB8000
#define VID_MEM_END 0xB87D0

/* VGA text mode colors */
#define VGA3_BLACK 0x0
#define VGA3_BLUE 0x1
#define VGA3_GREEN 0x2
#define VGA3_CYAN 0x3
#define VGA3_RED 0x4
#define VGA3_MAGENTA 0x5
#define VGA3_BROWN 0x6
#define VGA3_LIGHT_GRAY 0x7
#define VGA3_DARK_GRAY 0x8
#define VGA3_LIGHT_BLUE 0x9
#define VGA3_LIGHT_GREEN 0xA
#define VGA3_LIGHT_CYAN 0xB
#define VGA3_LIGHT_RED 0xC
#define VGA3_LIGHT_MAGENTA 0xD
#define VGA3_YELLOW 0xE
#define VGA3_WHITE 0xF

/* And the computer said, let there be light */
/* (16 colors of it) */
#define VGA3_COLOR(FORE, BACK) ((BACK << 4) + FORE)

#endif //KITTY_VGA3_H

