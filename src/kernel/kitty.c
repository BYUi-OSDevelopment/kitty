//
// Created by AIDAN PRATT on 10/28/2023.
//

#include <stdint.h>
#include "kitty.h"
#include "../driver/video/vga.h"
#include "../cpu/cpu_options.h"
#ifdef x86_64
#include "../cpu/x86_64/idt.h"
#endif

void kitty() {
    // Perform initial setup for CPUs
#ifdef Intel_CPU
    write_string(vga3_color(VGA3_CYAN, VGA3_RED),"Starting the Kitty Kernel...");
    init_idt();
    write_string_at(VGA3_WHITE, "idt loaded", 0,15);
#endif
#ifdef ARM_CPU

#endif
    while (1);
}