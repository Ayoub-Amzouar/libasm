	section .text
	extern	_ft_create_elem

	global	_ft_list_push_front

; create a function that creates an element of linked list

_ft_list_push_front:
	push rdi
	mov rdi, rsi
	call _ft_create_elem
	pop rdi
	mov rsi, [rdi]
	mov qword [rax+8], rsi
	mov [rdi], rax
	ret
