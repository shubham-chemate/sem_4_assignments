%macro rwm 03

    mov rax, %1

    mov rdi, 01

    mov rsi, %2

    mov rdx, %3

    syscall

%endmacro rwm



section .data

    msg1 db "Enter String: "

    l1 equ $ -msg1

    

    msg2 db "Length of String is: "

    l2 equ $ -msg2

    

    slen db 00

    newline db 0xA

    

section .bss

    mystr resb 30

    

global _start

section .text

_start:

    

    rwm 01, msg1, l1                ; displaying msg

    rwm 00, mystr, 30               ; reading string

    

    cmp al, 09h

    jc l   

    add al, 07h

l:   

    add al, 30h                     

    mov byte[slen], al

    

    rwm 01, msg2, l2

    rwm 01, slen, 01                ; displaying str len

    rwm 01, newline, 01

    

    ; exit

    mov rax, 60

    mov rdi, 00

    syscall

    