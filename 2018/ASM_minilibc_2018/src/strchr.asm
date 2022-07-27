BITS 64

global strchr
section .text

strchr:
    push rbp
    mov rbp, rsp

_begin:
    cmp byte [rdi], sil
        je _found
    cmp byte [rdi], 0
        je _not_found
    inc rdi
    jmp _begin

_not_found:
    mov rax, 0
    jmp _end

_found:
    mov rax, rdi
    jmp _end

_end:
    mov rsp, rbp
    pop rbp
    ret

