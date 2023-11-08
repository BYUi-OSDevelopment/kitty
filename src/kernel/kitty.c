//
// Created by AIDAN PRATT on 10/28/2023.
//

#include "kitty.h"
#include "../driver/video/vga.h"

void kitty() {
    while (1) {
        struct color new_color;
        new_color.red = 255;
        new_color.blue = 0;
        new_color.green = 0;
        char guh[] = "i am popping off ngl";
        write_string(1, guh);
    }
}