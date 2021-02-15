	section		.text
	global		ft_strcmp

; rcx: i 
; r8: j
; rdi: s1
; rsi: s2

ft_strcmp:
	xor rcx, rcx
	xor r8, r8

cmp_s1:
	cmp byte [rdi + rcx], 0
	je return_value
	mov al, byte [rdi + rcx]
	cmp al, byte [rsi + r8]
	jne return_value
	inc rcx
	jmp cmp_s2

cmp_s2:
	cmp byte [rsi + r8], 0
	je return_value
	mov al, byte [rsi + r8]
	cmp al, byte [rdi + rcx]
	jne return_value
	inc r8
	jmp cmp_s1

return_value:
	mov rax, [rdi + rcx*8]
	sub rax, [rsi + r8*8]
	ret