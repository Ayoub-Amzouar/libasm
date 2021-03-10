	section .text
	extern _malloc
	extern _ft_strcpy
	extern _ft_strlen
	extern ___error

	global _ft_strdup

_ft_strdup:
	push rdi
	call _ft_strlen
	mov rdi, rax
	inc rdi
	call _malloc
	jc return_value
	pop rsi
	mov rdi, rax
	call _ft_strcpy
	ret

return_value:
	push rax
	call ___error
	pop qword [rax]
	mov rax, 0
	ret