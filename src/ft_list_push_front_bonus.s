	section .text
	extern	_ft_create_elem

	global	_ft_list_push_front



_ft_list_push_front:
	push rdi
	mov rdi, rsi
	call _ft_create_elem
	pop rdi
	mov rsi, [rdi]
	mov qword [rax+8], rsi
	mov [rdi], rax
	ret
