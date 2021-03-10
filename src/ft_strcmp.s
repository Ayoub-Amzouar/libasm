	section		.text
	global		_ft_strcmp

; rdi: s1
; rsi: s2

_ft_strcmp:
	xor rax, rax
	xor rcx, rcx
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
	jmp _ft_strcmp

return_value:
	sub eax, ecx
	ret