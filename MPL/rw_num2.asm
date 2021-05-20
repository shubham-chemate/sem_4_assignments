section .data

    msg1 db "Enter num: ", 0xA    

    msg2 db "Showing Output:", 0xA    

    cnt db 00h



section .bss

    arr resb 85

    

section .text

global _start

_start:

    

    ; getting input

    mov rax, 01

    mov rdi, 01

    mov rsi, msg1

    mov rdx, 11

    syscall

    

    mov byte[cnt], 05

    mov rsi, arr

    mov rbx, 00

    

loop:



    mov rax, 00

    mov rdi, 01

    add rsi, rbx

    mov rdx, 17

    syscall

    

    add rbx, 17

    dec byte[cnt]

    jnz loop

    

    ; printing output

    

    mov rax, 01

    mov rdi, 01

    mov rsi, msg2

    mov rdx, 16

    syscall

    

    mov rbx, 00

    mov byte[cnt], 05

    mov rsi, arr

    

loop2:



    mov rax, 01

    mov rdi, 01

    add rsi, rbx

    mov rdx, 17

    syscall

    

    add rbx, 17

    dec byte[cnt]

    jnz loop2

    

    ; exit

    mov rax, 60

    mov rdi, 00

    syscall

    