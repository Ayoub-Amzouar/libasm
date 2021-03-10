	section .text
	extern ___error

	global _ft_read

_ft_read:
	mov rax, 0x02000003
	syscall
	jc return_error
	ret

return_error:
	push rax
	call ___error
	pop qword [rax]
	mov rax, -1
	ret