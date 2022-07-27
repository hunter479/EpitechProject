BITS 64

global strlen
section .text

strlen:
    push rbp
    mov rbp, rsp
    xor rcx, rcx

_begin:
    cmp byte [rdi], 0
        je _end
    inc rdi
    inc rcx
    jmp _begin
_end:
    mov rax, rcx

    mov rsp, rbp
    pop rbp
    ret
