section .text
    global ft_list_push_front
    extern malloc

; rdi = begin_list (pointer to pointer to t_list)
; rsi = data (pointer to void)
ft_list_push_front:
    PUSH rbp
    MOV rbp, rsp
    
    PUSH rdi    ; begin_list
    PUSH rsi    ; data - preserve rsi before malloc call
    
    ; Allocate memory for new node (16 bytes: 8 for data pointer + 8 for next pointer) (t_list is 16 bytes)
    MOV rdi, 16
    CALL malloc
    
    ; Restore parameters
    POP rsi     ; data
    POP rdi     ; begin_list

    ; Check if malloc failed
    CMP rax, 0
    JE .end
    
    ; Set up the new node
    MOV [rax], rsi      ; new_node->data = data
    MOV rcx, [rdi]      ; rcx = *begin_list (current first element)
    MOV [rax + 8], rcx  ; new_node->next = *begin_list
    MOV [rdi], rax      ; *begin_list = new_node

.end:
    MOV rsp, rbp
    POP rbp
    RET
