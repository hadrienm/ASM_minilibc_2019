BITS 64
global memcpy

memcpy:
    push rbp                ; Prologue
    mov rbp, rsp            ; (==enter)

    mov rax, rdi            ; result = dst
    mov r9b, 0              ; char temp = NULL
    mov r10, 0              ; i = 0
    cmp rsi, 0              ; if (str == NULL)
    je .end                 ; return NULL
    cmp rdx, 0              ; if (index == 0)
    je .end                 ; return NULL

.loop:                      ; while
    cmp edx, r10d           ; if (i == index)
    je .end                 ; return dst
    mov r9b, [rsi + r10]    ; temp = src[i]
    mov [rdi + r10], r9b    ; dst[i] = tmp;
    inc r10d                ; ++i
    jmp .loop

.end:
    leave
    ret
