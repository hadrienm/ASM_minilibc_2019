BITS 64
global strcspn

strcspn:
    push rbp                        ; Prologue
    mov rbp, rsp                    ; (==enter)
    mov rax, 0                      ; result = NULL
    mov r8d, 0                      ; int tmp_index = 0
    mov r9d, 0                      ; int i = 1
    mov r10b, 0                     ; char tmp = NULL

.loop:
    mov r8d, 0                      ; tmp_index = 0
    cmp byte [rdi], 0               ; s[i] == NULL
    je .setreturn
    jmp .secondloop                 ; double for
    
.secondloop:
    mov r10b, [rsi + r8]            ; tmp = charset[i]
    cmp r10b, 0                     ; if (tmp == NULL)
    je .inc
    cmp [rdi], r10b                 ; if (s[i] == tmp)
    je .setreturn
    inc r8d                         ; ++tmp_index
    jmp .secondloop

.inc:
    inc rdi                         ; ++s
    inc r9d                         ; ++i
    jmp .loop

.setreturn:
    mov rax, r9                     ; result = i
    jmp .end

.end:
    leave
    ret
