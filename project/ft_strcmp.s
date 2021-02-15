	section		.text
	global		ft_strcmp

; rdi: s1
; rsi: s2

ft_strcmp:
	mov al, byte [rdi]
	mov cl, byte [rsi]
	cmp al, 0
	je return_value
	cmp cl, 0
	je return_value
	inc rdi
	inc rsi
	cmp al, cl
	jne return_value
	jmp ft_strcmp

return_value:
	xor rax, rax
	mov rax, rbx
	ret