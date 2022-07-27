BITS 64

global memset
section .text

memset:
    push rbp
    mov rbp, rsp

    xor rcx, rcx

_begin:
    cmp rcx, rdx
        je _end
    mov byte [rdi + rcx], sil
    inc rcx
    jmp _begin

_end:
    mov rax, rdi
    mov rsp, rbp
    pop rbp
    ret