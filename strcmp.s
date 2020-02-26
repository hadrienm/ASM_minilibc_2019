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
    jne .setreturn
    cmp r10b, 0                     ; if (str1[i] == '\0' || str2[i] == '\0')
    je .end                         ; return 0
    inc rdi                         ; str1++
    inc rsi                         ; str2++
    jmp .loop

.setreturn:
    sub r9b, r10b
    mov al, r9b 
    jmp .end

.end:
    leave
    ret
