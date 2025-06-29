section .text
	global ft_strcpy

ft_strcpy:
    PUSH rbp
    MOV rbp, rsp
    MOV rax, rdi

.loop:
    MOV bl, [rsi]
    MOV [rdi], bl
    CMP bl, 0
    JE .end
    INC rsi
    INC rdi
    JMP .loop

.end:
    MOV rsp, rbp
    POP rbp
    RET