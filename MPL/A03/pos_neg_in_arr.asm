; Shubham (Roll No: 21118)
; Subject MPL

%macro rwm 3
        mov rax, %1
        mov rdi, 01 
        mov rsi, %2
        mov rdx, %3
        syscall
%endmacro

section .data
        arr dq -1111111111111111h, -1111111100000000h, 7999999999999999h, 0AAAAAAAAAAAAAAAAh, 55555555555555h
        n equ 5
        
        pmsg db "The Count of Positive No: "
        plen equ $-pmsg
        
        nmsg db "The Count of Negative No: ",
        nlen equ $-nmsg
        
        nwln db 0xA
    
section .bss
        pcnt resq 1
        ncnt resq 1
        ascii_num resb 16
    
section .text
        global _start
        
        _start:
                mov rsi,arr
                mov rdi,n
                mov qword[pcnt], 0
                mov qword[ncnt], 0
        
        pos_neg_cnt:    
        		mov rax,[rsi]
                cmp rax,0000000000000000h
                js neg_inc
    
        pos_inc:    
        		inc qword[pcnt]
                jmp next
        neg_inc:     
        		inc qword[ncnt]
    
        next:    
        		add rsi,8
                dec rdi
                jnz pos_neg_cnt
				
				; printing positive nums
                rwm 1,pmsg,plen
                mov rax,[pcnt]
                call conv_and_display	; hex to ascii conversion
 				rwm 1,nwln,1
				
				; printing neg nums
                rwm 1,nmsg,nlen
                mov rax,[ncnt]
                call conv_and_display	; hex to ascii conversion
				rwm 1,nwln,1
				
				; exit syscall
                mov rax,60
                mov rbx,0
                syscall
        
        
;conv_and_disp procedure -> convert hex to ascii     
conv_and_display:
        mov rsi,ascii_num+15
        mov rcx,16

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
                
        rwm 1,ascii_num,16
ret