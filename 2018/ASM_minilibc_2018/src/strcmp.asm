BITS 64

global strcmp
section .text

strcmp:
    push rbp
    mov rbp, rsp
    xor r8, r8
    xor r9, r9

_begin:
    mov r8b, byte [rsi]
    cmp byte [rdi], r8b
        jne _diff
    cmp byte [rdi], 0
        je _same
    inc rdi
    inc rsi
    jmp _begin

_diff:
    mov r9b, [rdi]
    sub r9b, r8b
    xor rax, rax
    movsx rax, r9b
    jmp _end

_same:
    mov rax, 0
    jmp _end

_end:
    mov rsp, rbp
    pop rbp
    ret