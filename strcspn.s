BITS 64
global stcspn

strcspn:
    push rbp                        ; Prologue
    mov rbp, rsp                    ; (==enter)
    mov rax, 0                      ; result = NULL
    mov r8d, 0                      ; int tmp_index = 0
    mov r9d, 0                      ; int i = 0
    mov r10b, 0                     ; char tmp = NULL

.loop:
    mov r8d, 0                      ; tmp_index = 0
    cmp byte [rdi], 0                    ; s[i] == NULL
    je .setreturn
    inc rdi                         ; ++s
    jmp .secondloop                 ; double for
    
.secondloop:
    mov r10b, [rsi + r8]
    cmp [rdi], r10b                 ; if (s[i] == charset[i])
    je .setreturn
    inc r9d                         ; ++i
    inc r8d                         ; ++tmp_index

.setreturn:
    mov rax, r9                     ; result = i
    jmp .end

.end:
    leave
    ret
