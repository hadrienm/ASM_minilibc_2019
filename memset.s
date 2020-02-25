BITS 64
global memset

memset:
    push rbp                    ; Prlogue
    mov rbp, rsp                ; (==enter)

    mov rax, rdi
    mov r10, 0                  ; i = 0
    cmp rdi, 0                  ; if (str == NULL)
    je .end                     ; return NULL

.loop:                          ; while
    cmp rdx, r10                ; if (i = size)
    je .end                     ; return
    mov [rdi + r10], sil        ; str[i] = 'char'
    inc r10                     ; ++i
    jmp .loop

.end:
    leave
    ret
