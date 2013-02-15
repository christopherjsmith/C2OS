[org 0x7c00]

mov bx, boot_msg
call print
call switch_to_pm

jmp $

%include "print.asm"
%include "disk_load.asm"
%include "gdt.asm"
%include "print32.asm"
%include "switch_pm.asm"

[bits 32]

BEGIN_PM:
	mov ebx, prot_msg
	call print32

	jmp $

boot_msg:
	db 'Booting ChrisOS...', 0x0D, 0x0A, 0
prot_msg:
	db 'Loaded 32-Bit Protected Mode', 0


times 510-($-$$) db 0
dw 0xaa55
