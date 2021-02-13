		section		.text
		global		ft_strlen

ft_strlen:
	xor rax, 0

loop:
	cmp byte [rdi + rax], 0
	je return_value
	inc rax
	jmp loop

return_value:
	ret