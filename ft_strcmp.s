section .text
    global ft_strcmp

ft_strcmp:
    PUSH rbp
    MOV rbp, rsp
    MOV rax, 0
    CMP rdi, rsi
    JE .end

.loop:
    MOV al, [rdi]
    MOV bl, [rsi]
    CMP al, bl
    JNE .found_diff
    CMP al, 0
    JE .equal
    INC rdi
    INC rsi
    JMP .loop

.equal:
    MOV rax, 0
    JMP .found_diff

.found_diff:
    SUB al, bl    
    MOVSX eax, al ; or MOVSX rax, al
    JMP .end

.end:
    MOV rsp, rbp
    POP rbp
    RET