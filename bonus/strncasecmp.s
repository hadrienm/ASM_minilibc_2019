BITS 64
global strcasecmp

strcasecmp:
    push rbp                        ; Prologue
    mov rbp, rsp                    ; (==enter)

    mov rax, 0                      ; result = 0
    mov r8d, 0                      ; int index = 0
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
    cmp r8d, edx                    ; if (index == n)
    je .end
    inc rdi                         ; str1++
    inc rsi                         ; str2++
    inc r8d                         ; ++index
    jmp .loop

.first:
    add r9d, 32                     ; str1[i] += 32
    cmp r9, r10                     ; if str1[i] == str2[i]
    je .incstr
    sub r9d, 64                     ; str[i] -= 64
    cmp r9, r10                     ; if str1[i] == str2[i]
    je .incstr
    mov rax, -1                     ; return -1
    jmp .end                        ; end

.second:
    add r9d, 32                     ; str1[i] += 32
    cmp r9, r10                     ; if str1[i] == str2[i]
    je .incstr
    sub r9d, 64                     ; str[i] -= 64
    cmp r9, r10                     ; if str1[i] == str2[i]
    je .incstr
    mov rax, 1                      ; return 1
    jmp .end                        ; end

.incstr:
    inc rdi                         ; str1++
    inc rsi                         ; str2++
    jmp .loop

.end:
    leave
    ret
