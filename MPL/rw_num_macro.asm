; macro for reading and writing

%macro rwm 03

    mov rax, %1

    mov rdi, 01

    mov rsi, %2

    mov rdx, %3

    syscall

%endmacro rwm



section .data

    msg db "Enter number:"

    len equ $ -msg

    

    msg1 db "Array:"

    len1 equ $ -msg1

    

    cnt db 00h

    new db 0xA

    

section .bss

    arr resb 85

    

section .text

global _start



_start:

    ; reading data

    

    mov rbx, arr

    mov byte[cnt], 05h

    

l:  

    rwm 01, msg, len   

    rwm 00, rbx, 17

    

    add rbx, 17

    dec byte[cnt]

    jnz l

    

    ; printing msg1 - Array and newline

    rwm 01, msg1, len1

    rwm 01, new, 1

    

    mov rbx, arr

    mov byte[cnt], 05h

    

    ; printing data

    

print:

    rwm 01, rbx, 17

    

    add rbx, 17

    dec byte[cnt]

    jnz print

    

    ; exit

    mov rax, 60

    mov rdi, 00

    syscall