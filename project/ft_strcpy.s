	section		.text
	global		_ft_strcpy

_ft_strcpy:
	xor r0, r0
	mov rax, rdi

copying:
	cmp byte [rsi + r0], 0
	je exit
	mov al, byte [rsi + r0]
	mov byte [rdi + r0], al
	inc r0
	jmp copying

exit:
	mov byte [rsi + r0], 0
	ret