BITS 64

global rindex
section .text

rindex:
    push rbp
    mov rbp, rsp
    xor r9, r9

_begin:
    cmp byte [rdi], 0
        je _end
    cmp byte [rdi], sil
        je _found
    inc rdi
    jmp _begin

_found:
    mov r9, rdi
    inc rdi
    jmp _begin

_end:
    mov rax, r9
    mov rsp, rbp
    pop rbp
    ret

