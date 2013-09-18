[org 0x7c00]
KERNEL_OFFSET equ 0x1000
mov [BOOT_DRIVE], dl

mov bp, 0x900
mov sp, bp

mov bx, boot_msg
call print

call load_kernel

call switch_to_pm

jmp $

%include "screen/print.asm"
%include "disk/disk_load.asm"
%include "pm/gdt.asm"
%include "screen/print32.asm"
%include "pm/switch_pm.asm"

[bits 16]
load_kernel:
	mov bx, load_msg
	call print

	mov bx, KERNEL_OFFSET
	mov dh, 15
	mov dl, [BOOT_DRIVE]
	call disk_load

	ret

[bits 32]

BEGIN_PM:
	mov ebx, prot_msg
	call print32
	            
	call KERNEL_OFFSET

	jmp $


BOOT_DRIVE db 0
boot_msg db 'Booting OS...', 0x0D, 0x0A, 0
prot_msg db 'Loaded 32-Bit Protected Mode', 0
load_msg db 'Loading kernel into memory.', 0

times 510-($-$$) db 0
dw 0xaa55
