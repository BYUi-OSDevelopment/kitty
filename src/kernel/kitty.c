//
// Created by AIDAN PRATT on 10/28/2023.
//
#include <stdint.h>
#include "kitty.h"
#include "../driver/video/vga.h"

void kitty() {
    char* string = "VGA3 Working :)";
    write_string(vga3_color(VGA3_GREEN, VGA3_LIGHT_BLUE), string);
}