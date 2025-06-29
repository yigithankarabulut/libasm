section .text
    global ft_strdup
    extern malloc
    extern ft_strlen
    extern ft_strcpy

; rdi = first arg (str)
; rsi = second arg (len)
; rax = return value
ft_strdup:
    PUSH rbp
    MOV rbp, rsp

    MOV rbx, rdi
    CALL ft_strlen

    INC rax

    MOV rdi, rax
    CALL malloc

    CMP rax, 0
    JE .end

    MOV rdi, rax
    MOV rsi, rbx
    CALL ft_strcpy

.end:
    MOV rsp, rbp
    POP rbp
    RET