BITS 64
global strchr

strchr:
    push rbp                           ; Prologue
    mov rbp, rsp                       ; (==enter)

    mov r10, 0                         ; i = 0
    cmp rdi, 0                         ; if (str == NULL)
    je .notfound                            ; return 0;

.loop:                                 ;while 
    cmp byte [rdi + r10], 0            ;str[i] != '\0'
    je .notfound
    cmp byte [rdi + r10], sil          ; if (str[i] == c)
    je .found
    inc r10                            ;++str
    jmp .loop

.notfound:
    mov rax, 0                         ; return NULL
    jmp .end

.found:
    add rdi, r10                       ; result = result[i]
    mov rax, rdi                       ; result = str
    jmp .end                           ; return result

.end:
    leave
    ret
