BITS 64
global rindex

rindex:
    push rbp                    ; Prologue
    mov rbp, rsp                ; (==enter)

    mov rax, 0                  ; result = NULL
    mov r9, 0                   ; int i = 0
    mov r10, 0                  ; int j = 0

.posend:                        ; while
    cmp byte [rdi + r9], 0      ; if str[i] == '\0'
    je .loop                    ;
    inc r9                      ; i++
    jmp .posend

.loop:
    cmp [rdi + r9], sil         ; if (str[i] == c)
    je .setreturn               ;
    cmp r9, 0                   ; if (i == 0)
    je .end                     ; return NULL
    dec r9                      ; i --
    jmp .loop

.setreturn:
    cmp r10, r9                 ; if (j == i)
    je .setvalue                ; return str
    inc r10                     ; j++
    inc rdi                     ; str++
    jmp .setreturn

.setvalue:
    mov rax, rdi                ; retun = str
    jmp .end

.end:
    leave
    ret
