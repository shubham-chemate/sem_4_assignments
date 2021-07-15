; 21118 Shubham
; MPL Assignment No: 04

%macro print 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro read 2
	mov rax,0
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro exit 0
	mov rax,60
	mov rdi,0
	syscall
%endmacro

section .data
	array : dq  01H, 02H, 03H, 04H, 05H, 00H, 00H, 00H, 00H, 00H
	ent : db 0x0A
	lent : equ $-ent
	colon : db " : "
	lencol : equ $-colon
	before : db "Before copy",10
	lenbe : equ $-before
	after : db "After copy",10
	lenaf : equ $-after

	menu :
	db "1 : Non-overlapping without string",10
	db "2 : Non-overlapping with string",10
	db "3 : Overlapping without string",10
	db "4 : Overlapping with string",10
	db "5 : Exit",10
	db "Enter your choice",10
	lenmenu : equ $-menu

	

section .bss
	data : resb 16
	cnt1 : resb 1
	cnt2 : resb 1
	choice : resb 2

global _start
section .text
_start:
	print menu,lenmenu
	read choice,2
	cmp byte[choice],31H
	JE NOWOS
	cmp byte[choice],32H
	JE NOWS
	cmp byte[choice],33H
	JE OWOS
	cmp byte[choice],34H
	JE OWS
	cmp byte[choice],35H
	JE exit

	; --------------- Labels to call procedures ---------------

	NOWOS :
	call CALL1
	exit

	OWOS :
	call CALL2
	exit

	NOWS :
	call CALL3
	exit

	OWS :
	call CALL4
	exit

	; --------------- Hex to Ascii conversion --------------- 

	h_to_a :
		mov rdi,data
		mov byte[cnt2],16

		UP1 :
			rol rbx,4
			mov dl,bl
			and dl,0FH
			cmp dl,09H
			jbe NEXT
			add dl,07H

		NEXT :
			add dl,30H
			mov byte[rdi],dl
			inc rdi
			dec byte[cnt2]
		JNZ UP1

		print data,16
	ret

	; --------------- Printing array --------------- 

	print_array :
		mov rsi,array 					;set source pointer to array 
		mov byte[cnt1],10 				;count is having 10 because number of numbers in array are 10

		UP :
			mov rbx,rsi				;first we print addresses so we move rsi for htoa conversion
			push rsi				;push rsi because we'll require rsi later
			call h_to_a

			print colon,lencol			;after printing address we print colon

			pop rsi					;pop rsi pushed earlier and we 
			mov rbx,qword[rsi]			;move byte[rdi] to rbx that is the number to be printed
			push rsi
			call h_to_a
								;after printing address colon and the data at that address 
			print ent,lent				;we print enter and loop for rest of the array
			pop rsi
			add rsi,8
			dec byte[cnt1]
		JNZ UP
	ret

	; --------------- Non overlapping without string instructions --------------- 

	CALL1 :

		print ent,lent				;print array before copying data
		print before,lenbe
		call print_array
				
		mov rsi,array				;set source index to first element of array
		mov rdi,array+40			;dest block starts after last element
		mov byte[cnt1],5

		UP2 :
			mov rax,qword[rsi]		;mov data from rsi to rdi using rax variable
			mov qword[rdi],rax		;rax is temp for copying
			add rsi,8
			add rdi,8
			dec byte[cnt1]
		JNZ UP2

		print ent,lent				;print array after copying the contents
		print after,lenaf
		call print_array
	ret


	; --------------- Overlapping without string --------------- 

	CALL2 : 
		print ent,lent				;print array before copying data
		print before,lenbe
		call print_array

		mov rsi,array				;first array element
		add rsi,32				;third last array element	
		mov rdi,rsi				;2 overlapping rdi begins from third last element to array
		add rdi,24
		mov byte[cnt1],5

		UP3 :
			mov rax,[rsi]			;mov data from rsi to rdi using rax variable
			mov [rdi],rax			;rax is temp for copying
			sub rsi,8
			sub rdi,8
			dec byte[cnt1]
		JNZ UP3

		print ent,lent				;print array after copying the contents
		print after,lenaf
		call print_array
	ret

	; --------------- Non overlapping with string --------------- 

	CALL3 :
		print before,lenbe
		call print_array

		mov rsi,array
		mov rdi,array+40
		mov byte[cnt1],5

		UP4:			
			CLD			;we clear the direction flag so that we'll increment array addresses automatically		
			movsq			;mov string of quadword for moving a complete string of data from source to destination
			dec byte[cnt1]
		JNZ UP4

		print ent,lent
		print after,lenaf
		call print_array
	ret

	; --------------- Overlapping with string --------------- 

	CALL4 :
		print before,lenbe
		call print_array

		mov rsi,array				;points to first location
		add rsi,32				; +4 goes to last block
		mov rdi,rsi				;des to last block
		add rdi,24				;overlapping two blocks 
		mov byte[cnt1],5

		UP5 :
			STD				;std to decrement, cld to increment direction flag
			movsq
			dec byte[cnt1]
		JNZ UP5

		print ent,lent
		print after,lenaf
		call print_array
	ret