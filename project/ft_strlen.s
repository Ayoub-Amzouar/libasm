		global		_start
		extern		_printf

		section		.text

_start:
mov rax, 0

loop:
	cmp byte [message + rax], 0
	je print
	inc rax
	jmp loop

print:
	push rax
	mov rdi, format
	mov rsi, message
	mov rdx, rax
	call _printf
	pop rax
	ret

		section		.data
message:	dq		"Hello World!", 0
format:		dq		"length of [%s] is %ld characters\n", 0