//
// Created by AIDAN PRATT on 10/28/2023.
//

#include <stdint.h>
#include "kitty.h"
#include "../driver/video/vga.h"
#include "../cpu/cpu_options.h"

void kitty() {
    // Perform initial setup for CPUs
#ifdef Intel_CPU
    write_string(vga3_color(VGA3_CYAN, VGA3_RED),"Starting the Kitty Kernel...");
#endif
    while (1);
}