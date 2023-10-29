; kitty kernel boot sector file
;
; Authors: 	BYU-I OS development team
; Git:		https://github.com/BYUi-OSDevelopment/kitty/
; Date:		2023-10-24

[org 0x7c00]			; boot sector starts at address 0x7c00

mov [BOOT_DRIVE], dl		; set boot drive to DL

mov cl, 0

; clears the screen, sets cursor position + page number
print_clear:
    mov ah, 0x00
    mov al, 0x03
    int 0x10
    mov ah, 0x02
    mov bh, 0
    mov dh, 0
    mov dl, 0
    int 0x10
mov bx, LOAD_TEXT
print_drive_menu: ; put address of LOAD_TEXT into bx!
    mov ah, 0x0e
    mov al, [bx]
    int 0x10
    inc bx
    cmp [bx], byte 0
    jne print_drive_menu
    cmp cl, byte 0 ; figure out what is selected, and put the cursor in the right place
    jne check_1
    mov dh, 2
    jmp print_x
    check_1:
    cmp cl, byte 1
    jne check_2
    mov dh, 3
    jmp print_x
    check_2:
    mov dh, 4
    print_x:
    mov ah, 0x02
    mov bh, 0
    mov dl, 4
    int 0x10
    mov ah, 0x0e
    mov al, 'X'
    int 0x10
    jmp get_input
get_input:
    mov ah, 0x00
    int 0x16
    cmp ah, 0x48
    je move_up
    cmp ah, 0x50
    je move_down
    cmp ah, 0x1C
    je load_kernel

move_up:
    cmp cl, 0
    je print_clear
    dec cl
    jmp print_clear
move_down:
    cmp cl, 2
    je print_clear
    inc cl
    jmp print_clear
; start boot process

load_kernel:
xor ax, ax			; set ax to 0
mov ds, ax			; set data segment (ds) to value of ax (0)
cld				; clear direction flag
mov ah, 0x02			; read sectors from drive
mov al, 63			; specify numbers of sectors in decimal
mov dh, 0			; specify drive head

cmp cl, byte 0
je default_drive_set
cmp cl, byte 1
je floppy_drive_set
cmp cl, byte 2
je hard_drive_set
default_drive_set:
mov dl, [BOOT_DRIVE]
jmp continue_copy
floppy_drive_set:
mov dl, 0x00
jmp continue_copy
hard_drive_set:
mov dl, 0x80
jmp continue_copy
continue_copy:			; specify drive
mov ch, 0			; start at cylinder 0
mov cl, 2			; start at sector 2
xor bx, bx			; make entire register 0s
mov es, bx			; now bx is starting point in RAM
mov bx, 0x7e00			; set bx to end of drive (address 0x7e00)

int 0x13			; load bios interrupt calls

enter_protected:
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or al, 1
    mov cr0, eax
    jmp (gdt_code - gdt_start):segment_switch

; DATA
gdt_start:
    dd 0x0
    dd 0x0

gdt_code:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10011010b
    db 11001111b
    db 0x0

gdt_data:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

BOOT_DRIVE:	db 0		; define BOOT_DRIVE label
LOAD_TEXT:
    db 'Please select a drive to boot off of:',0xA, 0xD,0xA, 0xD,'   [ ] Default Drive',0xA, 0xD,'   [ ] Floppy Drive',0xA, 0xD,'   [ ] Hard Drive',0xA, 0xD
    db ' _                    ',0xA, 0xD
    db '| | __ _ _______ _ __ ',0xA, 0xD
    db '| |/ _` |_  / _ \  __|',0xA, 0xD
    db '| | (_| |/ /  __/ |   ',0xA, 0xD
    db '|_|\__,_/___\___|_|   '
    db 0		; text

[bits 32] ; code again

segment_switch:
    mov ax, (gdt_data - gdt_start)
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000
    mov esp, ebp
    jmp 0x1000

; the following code populates the first 512 bytes of the drive
times 510-($-$$) db 0		; for 510 bytes minus the beginning of file, write 0
dw 0xAA55			; magix number