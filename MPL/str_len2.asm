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

    

    newline db 0xA

    

section .bss

    mystr resb 30

    slen resb 02

    cnt resb 01

    

global _start

section .text

_start:

    

    rwm 01, msg1, l1                ; displaying msg

    rwm 00, mystr, 30               ; reading string

    

    mov byte[cnt], 02               ; counter

    mov rsi, slen                   ; rsi point to first loc of str len array

    

again:                              ; loop for each digit of hex

    rol al, 04                      ; rol for rightmost digit

    mov bl, al

    and bl, 0fh                     ; bl stores digit (rightmost)

    cmp bl, 09h                     ; next 5 lines => hex->ASCII for single digit

    jbe add30h

    add bl, 07h

add30h:

    add bl, 30h

    mov [rsi], bl                   ; mov digit to str len array

    add rsi, 01                     ; rsi will point to next location of str

                                    ; len array

    dec byte[cnt]

    jnz again

    

    rwm 01, msg2, l2

    rwm 01, slen, 02                ; print strlen array

    rwm 01, newline, 01

    

    ; exit syscall

    mov rax, 60

    mov rdi, 00

    syscall

    