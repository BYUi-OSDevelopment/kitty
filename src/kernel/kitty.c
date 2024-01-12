//
// Created by AIDAN PRATT on 10/28/2023.
//
#include <stdint.h>
#include "kitty.h"
#include "../driver/video/vga.h"

void kitty() {
    while (1) {
        write_string(0b00001111,"guh");
        //write_string(vga3_color(VGA3_WHITE,VGA3_BLACK),"wow");

    }

}