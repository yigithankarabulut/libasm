section .text
    global ft_list_size

; rdi = begin_list
; rax = return value
ft_list_size:
    ; function prologue/epilogue
    PUSH rbp
    MOV rbp, rsp
    XOR rax, rax

.loop:
    CMP rdi, 0
    JE .end
    INC rax
    MOV rdi, [rdi + 8] ; size of t_list is 8 because pointer to next is 8 bytes
    JMP .loop
    

.end:
    MOV rsp, rbp
    POP rbp
    RET
