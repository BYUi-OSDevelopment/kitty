//
// VGA3.C
//
// Controls VGA text mode.
//
// Created by BRADY MCDERMOTT on 1/11/2024.
//
#include <stdint.h>
#include <stdbool.h>
#include "vga3.h"

/* VGA3 Write String */
// Writes a string to the screen
// with a color & string input.
void vga3_write_string(uint8_t color, uint8_t *p_string )
{
	vga3char *p_vga3char;
    vga3char *p_vid_location;
    uint8_t *p_str_location;
	
	// Set location of the video memory pointer
	p_vid_location = VID_MEM_START;
	
	// Get the string's memory address
	p_str_location = p_string;
	
    do {
		// Set the character from the string
		p_vga3char->character = *p_str_location;
		
		// Copy the color value to the structure
		p_vga3char->vga3_color = color;
		
		// Display the character on the screen
        *p_vid_location = *p_vga3char;
		
		// Increment...
        p_str_location++;
        p_vid_location++;
    } while ( *p_str_location != 0 && p_vid_location < VID_MEM_END);

}

uint8_t inline vga3_get_color(uint8_t fore, uint8_t back) {
    return ((back << 4) + fore);
}