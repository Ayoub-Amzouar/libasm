	section	.text

	global	_ft_list_sort

; rdi: *head
; rdx: pointer to a compare function
; rcx: (*head)->next
; r8: tmp variable

_ft_list_sort:
	mov	rdi, [rdi]
	mov rdx, rsi

loop1:
	cmp rdi, 0
	je return_value
	mov rcx, qword [rdi+8]
	jmp loop2

loop2:
	cmp rcx, 0
	je replay
	push rdi
	push rcx
	push rdx
	mov rdi, qword [rdi]
	mov rsi, qword [rcx]
	call rdx
	cmp rax, 1
	pop rdx
	pop rcx
	pop rdi
	jz swap
	mov rcx, qword [rcx+8]
	jmp loop2

swap:
	push qword [rdi] ; we push rdi which is *head to save its value
	mov r8, qword [rcx] ; we put the address of the member data
	mov qword [rdi], r8 ; we put that address into the (*head)->data 
	pop r8
	mov qword [rcx], r8
	mov rcx, qword [rcx+8] ; tmp = tmp->next
	jmp loop2

replay:
	mov rdi, qword [rdi+8] ; (*head) = (*head)->next
	jmp loop1

return_value:
	ret