BITS 64
global stpbrk

strpbrk:
    push rbp                        ; Prologue
    mov rbp, rsp                    ; (==enter)
    mov rax, 0                      ; result = NULL
    mov r8d, 0                      ; int tmp_index = 0
    mov r9d, 0                      ; int i = 0
    mov r10b, 0                     ; char tmp = NULL

.loop:
    mov r9d, 0                      ; i = 0
    mov r10b, 0                     ; tmp = NULL
    cmp rsi, 0                      ; if (charset == NULL)
    je .end                         ; return NULL
    jmp .check                      ; double for

.check:
    mov r10b, [rdi + r9]            ; tmp = s[i]
    cmp r10b, [rsi]                 ; if (tmp == charset[i])
    je .incs
    cmp r10b, 0                     ; if (s[i] == NULL)
    je .loop
    inc rsi                         ; ++charset
    jmp .loop

.incs:
    cmp r8d, r9d                    ; if (tmp_index == i)
    je .setreturn                   ; return s
    inc r8d                         ; ++tmp_index
    inc rdi                         ; ++s
    jmp .incs

.setreturn:
    mov rax, rdi                    ; result = s
    jmp .end                        ; return s

.end:
    leave
    ret
