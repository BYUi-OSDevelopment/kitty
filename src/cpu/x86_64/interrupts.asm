;
; Created by AIDAN PRATT on 7/1/2024.
;

[bits 64]

%macro isr_common 1
    cli

%endmacro

%macro isr_end 1
    sti
    push rax
    mov al, 0x20
    out 0x20, al
    %if %1 >= 8
        out 0x21, al
    %endif
    pop rax
    iretq
%endmacro

%macro isr_complete 2
[extern %2]

global isr_%1
isr_%1:
    isr_common %1
    call %2
    isr_end %1
%endmacro

[extern divide_by_zero_interrupt]

global isr_0
isr_0:
    isr_common 0
    call divide_by_zero_interrupt
    isr_end 0

[extern debug_interrupt]

global isr_1
isr_1:
    isr_common 1
    call debug_interrupt
    isr_end 1

[extern non_maskable_interrupt]

global isr_2
isr_2:
    isr_common 2
    call non_maskable_interrupt
    isr_end 2

[extern breakpoint_interrupt]

global isr_3
isr_3:
    isr_common 3
    call breakpoint_interrupt
    isr_end 3


[extern overflow_interrupt]

global isr_4
isr_4:
    isr_common 4
    call overflow_interrupt
    isr_end 4


[extern unmapped_interrupt]

global isr_90:
isr_90:
    isr_common 90
    push rdi
    mov rdi, 90
    call unmapped_interrupt
    pop rdi
    isr_end 90

