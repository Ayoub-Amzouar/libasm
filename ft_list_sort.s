	section	.text

	global	_ft_list_sort

; rdi: *head
; rdx: pointer to a compare function
; rcx: (*head)->next

_ft_list_sort:
	mov	rdi, [rdi]
	mov rdx, rsi

loop1:
	cmp rdi, 0
	je return_value
	mov rcx, qword [rdi+8]
	jmp loop2
	mov rdi, qword [rdi+8]
	jmp loop1

loop2:
	cmp rcx, 0
	je loop1
	push rdi
	push rcx
	push rdx
	mov rdi, qword [rdi]
	mov rsi, qword [rcx]
	call rdx
	cmp rax, 0
	jg swap
	pop rdx
	pop rcx
	pop rdi
	mov rcx, qword [rcx+8]
	jmp loop2

swap:


return_value:
	ret