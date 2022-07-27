BITS 64

global strncmp
section .text

strncmp:
    push rbp
    mov rbp, rsp
    xor r8, r8
    xor rcx, rcx

_begin:
    mov byte r8b, [rsi]
    cmp rdx, rcx
        je _same
    cmp byte [rdi], r8b
        jne _diff
    cmp byte [rdi], 0
        je _same
    inc rdi
    inc rsi
    inc rcx
    jmp _begin

_diff:
    xor r9, r9
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