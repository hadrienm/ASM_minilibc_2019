BITS 64
global memcpy

memcpy:
    push rbp                ; Prologue
    mov rbp, rsp            ; (==enter)

    mov r10, 0              ; i = 0
    cmp rsi, 0             ; if (str == NULL)
    je .setreturn           ; return NULL
    cmp rdx, 0              ; if (index == 0)
    je .setreturn           ; return NULL

.loop:                      ; while
    cmp rdx, r10            ; if (i == index)
    je .end
    mov rdi, [rsi + r10]    ; newstr[i] = str[i];
    inc r10                 ; ++i
    jmp .loop

.setreturn:
    mov rax, 0
    jmp .end

.end:
    leave
    ret
