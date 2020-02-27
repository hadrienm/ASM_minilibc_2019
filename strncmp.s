BITS 64
global strncmp

strncmp:
    push rbp                        ; Prologue
    mov rbp, rsp                    ; (==enter)

    mov rax, 0                      ; result = 0
    mov r9d, 0                      ; char a = NULL
    mov r10d, 0                     ; char b = NULL
    mov r8d, 0                      ; int index = 0

.loop:                              ; while
    cmp r8d, edx                    ; if (index == n)
    je .end                         ; return
    mov r9b, [rdi]                  ; a = str1
    mov r10b, [rsi]                 ; b = str2
    cmp byte r9b, r10b              ; if (str1[i] < str2[i])
    jl .first                       ; return -1
    jg .second                      ; return 1
    cmp r9b, 0                      ; if (str1 == NULL)
    je .first                       ; return -1
    cmp r10b, 0                     ; if (str2 == NULL)
    je .second                      ; return 1
    inc rdi                         ; str1++
    inc rsi                         ; str2++
    inc r8d                         ; ++index
    jmp .loop

.first:
    mov rax, -1                     ; return -1
    cmp r10b, 0                     ; if (str2 == NULL)
    je .both                        ; both
    jmp .end                        ; end

.second:
    mov rax, 1                      ; return 1
    mov r9b, 0                      ; if (str1, NULL)
    je .both                        ; both
    jmp .end                        ; end

.both:
    mov rax, 0                      ; return 0
    jmp .end                        ; end

.end:
    leave
    ret
