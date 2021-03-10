	section .text
	extern ___error

	global _ft_write

_ft_write:
	mov rax, 0x02000004
	syscall
	jc return_error
	ret

return_error:
	push rax
	call ___error
	pop qword [rax]
	mov rax, -1
	ret