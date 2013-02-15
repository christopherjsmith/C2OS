print:
	pusha
	mov ah, 0x0e
print_c:
	mov cx, [bx]
	cmp cx, 0
	je end_print
	mov al, [bx]
	int 0x10
	inc bx
	jmp print_c
end_print:
	popa
	ret
