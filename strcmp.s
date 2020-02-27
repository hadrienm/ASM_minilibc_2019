BITS 64
global strcmp

strcmp:
    push rbp                        ; Prologue
    mov rbp, rsp                    ; (==enter)

    mov rax, 0                      ; result = 0
    mov r9d, 0                      ; char a = NULL
    mov r10d, 0                     ; char b = NULL

.loop:                              ; while
    mov r9b, [rdi]                  ; a = str1
    mov r10b, [rsi]                 ; b = str2
    cmp byte r9b, r10b              ; if (str1[i] < str2[i])
    jl .first                       ; return -1
    jg .second                      ; return 1
    cmp r9b, 0                      ; if (str1 == NULL)
    je .end                         ; return 0
    inc rdi                         ; str1++
    inc rsi                         ; str2++
    jmp .loop

.first:
    mov rax, -1                     ; return -1
    jmp .end                        ; end

.second:
    mov rax, 1                      ; return 1
    jmp .end                        ; end

.end:
    leave
    ret
