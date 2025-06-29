section .text
	global ft_strlen
ft_strlen:
	PUSH rbp
	MOV rbp, rsp
	MOV rax, 0          ; Initialize counter to 0
	
.loop:
	CMP byte [rdi + rax], 0  ; Compare current character with null terminator
	JE .end                  ; If null terminator found, jump to end
	INC rax                  ; Increment counter
	JMP .loop                ; Continue loop
	
.end:
	MOV rsp, rbp
	POP rbp
	RET
