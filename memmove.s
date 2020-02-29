BITS 64
global memmove

memmove:
    push rbp                        ; Prologue
    mov rbp, rsp                    ; (==enter)

    mov rax, rdi                    ; result = dest
    mov r10, 0                      ; int i = 0
    cmp rdi, 0                      ; if (dst == NULL)
    je .end                         ; return dst
    cmp rsi, 0                      ; if (src == NULL)
    je .end                         ; return dst
    cmp rdx, 0                      ; if (len == 0)
    je .end                         ; return dst

.loop:                              ; while
    cmp rdx, r10                    ; if (i == len)
    je .end                         ; return dst
    add rdi, [rsi + r10]            ; newstr += src[i]
    inc r10                         ; ++i
    jmp .loop

.end:
    leave
    ret
