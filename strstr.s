BITS 64
global strstr

strstr:
    push rbp                        ; Prologue
    mov rbp, rsp                    ; (==enter)

    mov rax, 0                      ; result = NULL

.loop:                              ; while
    mov r8, 0                       ; tmp_str1 = NULL
    mov r9, 0                       ; index_str2 = 0
    mov r10, 0                      ; index = 0
    mov r11, 0                      ; tmp_str2 = 0
    jmp .check

.inc:
    cmp byte [rdi], 0               ; if (haystac == NULL)
    je .end                         ; return NULL
    inc rdi                         ; ++haystac
    jmp .loop

.check:                             ; while
    mov r8b, byte [rdi + r10]       ; tmp_str1 = haystac[index]
    mov r11b, byte [rsi + r9]       ; tmp_str2 = str2[index_str2]
    cmp r11b, 0                     ; if (tmp_str2 == NULL)
    je .setreturn  
    cmp r8b, r11b                   ; if (tmp_str1 != tmp_str2)
    jne .inc                        ; break
    cmp r8b, 0                      ; if (tmp_str1 == NULL)
    je .inc                         ; break;
    inc r9                          ; ++index_str2
    inc r10                         ; ++index
    jmp .check

.setreturn:
    mov rax, rdi                    ; result = haystac

.end:
    leave
    ret
