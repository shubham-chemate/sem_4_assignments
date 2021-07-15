; Shubham (21118)
; MPL Assignment 05

%macro rwm 3
        mov rax, %1
        mov rdi, 01 
        mov rsi, %2
        mov rdx, %3
        syscall
%endmacro

section .data

		opnd1 dq 0000000000000007 ; operands for binary arithematic operations
		opnd2 dq 0000000000000003

		menu: db "Enter", 0xA, "1 for Addition", 0xA,  "2 for Subtraction", 0xA,  "3 for Multiplication", 0xA, "4 for Division", 0xA, "0 to Exit", 0xA, ": "
		menul equ $-menu
		
		q db "Quotient : "
		m1: equ $-q
		
		nwln db 0xA

section .bss

		ascii_num resb 16 ; array for storing ascii of hex
		choice resb 02 ; users choice to perform operation

section .text

global _start

_start:
		
				rwm 01, menu, menul
				rwm 00, choice, 02 ; getting operation choice
			
				cmp byte[choice], 30h
				JE exit	; je -> jmp if equal			
				cmp byte[choice], 31h
				JE op1				
				cmp byte[choice], 32h
				JE op2		
				cmp byte[choice], 33h
				JE op3			
				cmp byte[choice], 34h
				JE op4
				JMP exit

		op1 : 
				call Addition
				JMP exit
		op2 : 
				call Subtraction
				JMP exit
		op3 : 
				call Multiplication
				JMP exit
		op4 :
				call Division
				JMP exit
	
		exit:
				mov rax,60
				mov rdi,0
				syscall

; Procedures for arithematic operations
		Addition:
				mov rax,[opnd1]
				mov rbx,[opnd2]
				add rax,rbx
				call conv_and_display
				rwm 01, nwln, 01
				ret

		Subtraction:
				mov rax,[opnd1]
				mov rbx,[opnd2]
				sub rax,rbx
				call conv_and_display
				rwm 01, nwln, 01
				ret

		Multiplication:
				mov rax,[opnd1]
				mov rbx,[opnd2]
				mul rbx
				mov r9,rax
				xor rax,rax ; clearing rax
				mov rax,rdx
				call conv_and_display ; displaying rdx
				xor rax,rax ; clearing rax
				mov rax,r9
				call conv_and_display ; displaying rax
				rwm 01, nwln, 01
				ret

		Division:
				mov rax,[opnd1]
				mov rbx,[opnd2]
				xor rdx,rdx ; clearing rdx
				div rbx
				mov r9,rax
				rwm 01, q, m1
				mov rax,r9
				call conv_and_display
				rwm 01, nwln, 01
				ret

; Procedure for hex to ascii converion
conv_and_display:
        mov rsi, ascii_num+15
        mov rcx, 16

        again:    
        	mov rdx,0
                mov rbx,16h ; 16 in hex == 10 in decimal
                ;(quotient and rem will be stored in rax and rdx resp)
                div rbx 	; on divide rem will be last digit 
                cmp dl,09h
                jbe add30
                add dl,07h
        add30:   
        		add dl,30h
                mov [rsi],dl
                dec rsi
                dec rcx
                jnz again
                
        rwm 01, ascii_num, 16
ret

				mov rax,60
				mov rdi,00
				Syscall
