BITS 64

global strcasecmp
section .text

strcasecmp:
    push rbp
    mov rbp, rsp
    xor r8, r8
    xor r9, r9

_jmp_start:

_isupper1:
    mov byte r8b, [rsi]
    cmp r8b, 65
        jl   _isupper2
    cmp r8b, 90
        jl   _tolower1

_isupper2:
    mov byte r9b, [rdi]
    cmp r9b, 65
        jl   _begin
    cmp r9b, 90
        jl   _tolower2

_begin:
    cmp byte r9b, r8b
        jne _diff
    cmp byte r9b, 0
        je _same
    inc rdi
    inc rsi
    jmp _jmp_start


_tolower1:
    add r8b, 32
    jmp _isupper2


_tolower2:
    add r9b, 32
    jmp _begin

_diff:
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