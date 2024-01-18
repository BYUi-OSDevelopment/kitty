//
// Created by AIDAN PRATT on 10/28/2023.
//
#include <stdint.h>
#include "kitty.h"
#include "../driver/video/vga.h"

void kitty() {
    while (1) {
        write_string(vga3_color(VGA3_CYAN, VGA3_RED),"whwatever we wandt");

    }


}