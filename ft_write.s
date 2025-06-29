section .text
    global ft_write
    extern __errno_location

ft_write:
    PUSH rbp
    MOV rbp, rsp

    MOV rax, 1  ; syscall number for write
    SYSCALL

    CMP rax, 0
    JL .error   ; Jump if less than 0 (error occurred)
    JMP .end

.error:
    ; Save the error code
    MOV r8, rax
    
    ; Call __error to get errno address
    CALL __errno_location
    
    ; Set errno to the negative of the error code
    NEG r8
    MOV [rax], r8
    
    ; Return -1
    MOV rax, -1

.end:
    MOV rsp, rbp
    POP rbp
    RET