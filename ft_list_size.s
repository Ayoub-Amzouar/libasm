	section	.text

	global _ft_list_size

_ft_list_size:
	xor	rax, rax

looping:
	cmp rdi, 0
	je return_value
	mov rdi, qword [rdi+8]
	inc rax

return_value:
	ret