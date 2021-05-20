%macro rwm 03

    mov rax, %1

    mov rdi, 01

    mov rsi, %2

    mov rdx, %3

    syscall

%endmacro rwm



section .data

    msg1 db "Enter number (Single Byte Expected): "

    len1 equ $ -msg1

    

    msg2 db "Largest Number is: "

    len2 equ $ -msg1

    

    sep db "------------------", 0xA

    len3 equ $ -sep

    

    cnt db 00h

    newline db 0xA

    

section .bss

    arr resb 10

    lg resb 01

    

section .text

global _start



_start:

    

    mov rbx, arr

    mov byte[cnt], 05h

    mov byte[lg], 00h

    

l:  

    rwm 01, msg1, len1  

    rwm 00, rbx, 02

    

    ; comparing number with largest

    ; --- comparison logic ---

    mov al, byte[rbx]

    cmp byte[lg], al

    jns normal_flow

    mov byte[lg], al

    

normal_flow:     

    add rbx, 02

    dec byte[cnt]

    jnz l

    

    

    ;rwm 01, sep, len3

    ;rwm 01, msg2, len2

    rwm 01, lg, 01

    rwm 01, newline, 01

    

    ; exit

    mov rax, 60

    mov rdi, 00

    syscall