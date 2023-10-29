global _start
[bits 32]
_start:
    [extern kitty]
    call kitty
    jmp $