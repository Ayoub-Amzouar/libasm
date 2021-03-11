	section	.text

	global	_ft_list_sort

; rdx: (*head)
; rcx: (*head)->next
; r8: compare function address

_ft_list_sort:
	mov rdx, [rdi]
	mov r8, rsi

loop1:
	cmp rdx, 0
	je exit
	mov rcx, qword [rdx+8]
	jmp loop2

loop2:
	cmp rcx, 0
	je next
	mov rdi, qword [rdx] ; putting data of linked list in another register
	mov rsi, qword [rcx]
	push rdx ; saving those registers to save them
	push rcx
	push r8
	call r8
	pop r8 ; get those registers back
	pop rcx
	pop rdx
	cmp rax, 0
	jg swap
	mov rcx, qword [rcx+8] ; increament
	jmp loop2

swap:
	mov rdi, qword [rdx] ; putting data of linked list in another register
	mov rsi, qword [rcx]
	mov qword [rdx], rsi ; swap them
	mov qword [rcx], rdi
	mov rcx, qword [rcx+8] ; increament
	jmp loop2


next:
	mov rdx, qword [rdx+8] ; increament --> (*head) = (*head)->next
	jmp loop1

exit:
	ret