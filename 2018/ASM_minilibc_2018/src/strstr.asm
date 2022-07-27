BITS 64

global strstr
section .text

strncmp:
    push rbp
    mov rbp, rsp
    xor rax, rax
    xor r8, r8
    xor r9, r9

_begin:

_not_find:
    cmp byte [rdi], 0
        je _end_not_find
    cmp byte [rdi], sil
        je _duplicate
    inc rdi

_duplicate:
    mov r9, rdi
    mov r8, rsi
    jmp _find

_find:
    cmp byte [r9], r8b
        jne _not_find
    cmp byte [r8], 0
        je _end
    inc r9
    inc r8

_end_not_find:
    mov rax, 0
    jmp _end

_end_find:
    mov rax, r9
    jmp _end

_end:
    mov rsp, rbp
    pop rbp
    ret