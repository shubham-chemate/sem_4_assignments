section .data

    msg1 db "Enter Number:"

    msg2 db "Showing Output:", 0xA



section .bss

    arr resb 85

    cnt resb 01

    

global _start

section .text



_start:

    

    ; ----------reading numbers-----------

    

    mov byte[cnt], 05                ; read_num Counter

    mov rbx, arr

    

read_num:



    mov rax, 01

    mov rdi, 01

    mov rsi, msg1

    mov rdx, 13

    syscall



    mov rax, 00

    mov rdi, 01

    mov rsi, rbx

    mov rdx, 17

    syscall

    

    add rbx, 17

    dec byte[cnt]

    jnz read_num

    

    ; ----------writing numbers-----------

    

    mov rax, 01

    mov rdi, 01

    mov rsi, msg2

    mov rdx, 16

    syscall

    

    mov byte[cnt], 05                 ; write_num Counter

    mov rbx, arr

    

write_num:



    mov rax, 01

    mov rdi, 00

    mov rsi, rbx

    mov rdx, 17

    syscall



    add rbx, 17

    dec byte[cnt]

    jnz write_num

    

    ; ----------Exit The Program-----------

    

    mov rax, 60

    mov rdi, 00

    syscall