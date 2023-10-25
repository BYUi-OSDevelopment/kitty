; kitty kernel boot sector file
;
; Authors: 	BYU-I OS development team
; Git:		https://github.com/BYUi-OSDevelopment/kitty/
; Date:		2023-10-24

[org 0x7c00]			; boot sector starts at address 0x7c00
xor ax, ax			; set ax to 0
mov ds, ax			; set data segment (ds) to value of ax (0)
cld				; clear direction flag

mov [BOOT_DRIVE], dl		; set boot drive to DL

mov ah, 0x02			; read sectors from drive
mov al, 63			; specify numbers of sectors in decimal
mov dh, 0			; specify drive head
mov dl, 0x80			; specify drive
mov ch, 0			; start at cylinder 0
mov cl, 2			; start at sector 2
xor bx, bx			; make entire register 0s
mov es, bx			; now bx is starting point in RAM
mov bx, 0x7e00			; set bx to end of drive (address 0x7e00)

int 0x13			; load bios interrupt calls
jmp stuff			; jump to the code beyond boot sector

BOOT_DRIVE:	db 0		; define BOOT_DRIVE label (labels are like gotos)

; the following code populates the first 512 bytes of the drive
times 510-($-$$) db 0		; for 510 bytes minus the beginning of file, write 0
dw 0xAA55			; 

; the following code populates what is beyond that 512 byte boot sector
stuff:	mov ah, 0x0e		; put BIOS in teletype mode (tty)
	mov al, 'x'		; print 'x' character
	int 0x10		; lead BIOS interrupt for video services

jmp $				; jump to current address (loops code here)
