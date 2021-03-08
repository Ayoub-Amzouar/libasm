	section .text
	extern ___error

	global _ft_write

_ft_write:
	mov rax, 0x02000004
	syscall
	jc return_error
	ret

return_error:
	mov r8, rax
	call ___error
	mov [rax], r8
	mov rax, -1
	ret