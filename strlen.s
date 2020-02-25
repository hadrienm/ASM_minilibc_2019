BITS 64
global strlen

strlen:
    push rbp                    ; Prologue
    mov rbp, rsp                ; (==enter)

    mov rax, 0                  ; int i = 0
    cmp rdi, 0                  ; if (str == NULL)
    je .end                     ; return 0;

.loop:                          ; while
    cmp byte [rdi + rax], 0     ; str[i] != '\0'
    je .end                     ; return i
    inc rax                     ; ++i
    jmp .loop

.end:
    leave
    ret
