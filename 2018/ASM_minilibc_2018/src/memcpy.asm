BITS 64

global memcpy
section .text

memcpy:
    push rbp
    mov rbp, rsp

    mov rax, rdi
    xor r9, r9
    xor rcx, rcx

_begin:
    cmp byte [rax + rcx], 0
        je _end
    cmp rcx, rdx
        je _end
    mov r9b, byte [rsi + rcx]
    mov byte [rax + rcx], r9b
    inc rcx
    jmp _begin

_end:
    mov rsp, rbp
    pop rbp
    ret