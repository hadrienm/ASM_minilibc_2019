BITS 64
global strchr

strchr:
    push rbp                           ; Prologue
    mov rbp, rsp                       ; (==enter)

    mov rax, 0
    mov r10, 0                         ; i = 0

.loop:                                 ;while 
    cmp byte [rdi + r10], sil          ; if (str[i] == c)
    je .found
    cmp byte [rdi + r10], 0            ;str[i] != '\0'
    je .end
    inc r10                            ;++str
    jmp .loop

.found:
    add rdi, r10                       ; result = result[i]
    mov rax, rdi                       ; result = str
    jmp .end                           ; return result

.end:
    leave
    ret
