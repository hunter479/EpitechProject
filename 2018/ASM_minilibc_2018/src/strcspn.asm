BITS 64

global strcspn
section .text

strcspn:
    push rbp
    mov rbp, rsp
    xor r8, r8
    xor r9, r9

_begin:
    xor rcx, rcx

_compare_s:
    mov r8b, byte [rsi + rcx]
    cmp r8b, 0
        je _compare
    cmp byte [rdi], r8b
        je _end
    inc rcx
    jmp _compare_s

_compare:
    cmp byte [rdi], 0
        je _end
    inc rdi
    inc r9
    jmp _begin

_end:
    mov rax, r9
    mov rsp, rbp
    pop rbp
    ret