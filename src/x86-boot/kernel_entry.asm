global _start;
[bits 64]
_start:
    [extern kitty]
    call kitty
    jmp $