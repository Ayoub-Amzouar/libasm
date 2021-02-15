		section		.text
		global		ft_strcpy

ft_strcpy:
	xor rcx, rcx

copying:
	cmp byte [rsi + rcx], 0
	je return_value
	mov al, byte [rsi + rcx]
	mov byte [rdi + rcx], al
	inc rcx
	jmp copying

return_value:
	mov byte [rdi + rcx], 0
	mov rax, rdi
	ret