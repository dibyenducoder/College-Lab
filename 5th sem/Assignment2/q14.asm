;14.Write and test a program to multiply two 8 bit numbers.

.model small
.stack 100h

.data
	prompt_1 db "Enter two numbers: ",10,13,"$"
	prompt_2 db "Their product is: $"
	new_line db 10,13,"$"

	num1 db ?
	num2 db ?

	;macro to display prompt and print string
	display macro msg
		mov ah,9
		lea dx,msg
		int 21h
	endm

.code

	;*********************************
	;**** decimal input **************
	; input: none
	; output: bx

	dec_input proc

	   @read:                         ; jump label
	   xor bx, bx                     ; clear bx
	   xor cx, cx                     ; clear cx

	   mov ah, 1                      ; set input function
	   int 21h                        ; read a character

	   cmp al, '-'                    ; compare al with "-"
	   je @minus                      ; jump to label @minus if al="-"

	   cmp al, '+'                    ; compare al with "+"
	   je @plus                       ; jump to label @plus if al="+"
	   jmp @input                     ; jump to label @input

	   @minus:                        ; jump label
	   mov cx, 1                      ; set cx=1

	   @plus:                         ; jump label
	   int 21h                        ; read a character
	   cmp al, 0dh                    ; compare al with cr
	   je @end                        ; jump to label @end if al=cr

	   @input:                        ; jump label

	     and ax, 000fh                ; convert ascii to decimal code

	     push ax                      ; push ax onto the stack

	     mov ax, 10                   ; set ax=10
	     mul bx                       ; set ax=ax*bx
	     mov bx, ax                   ; set bx=ax

	     pop ax                       ; pop a value from stack into ax

	     add bx, ax                   ; set bx=ax+bx

	     mov ah, 1                    ; set input function
	     int 21h                      ; read a character

	     cmp al, 0dh                  ; compare al with cr
	     jne @input                   ; jump to label if al!=cr
	                                   
	   @end:                          ; jump label

	   or cx, cx                      ; check cx is 0 or not
	   je @exit                       ; jump to label @exit if cx=0
	   neg bx                         ; negate bx

	   @exit:                         ; jump label

	   ret                            ; return control to the calling procedure

	dec_input endp
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	;************************************************
	; decimal output
	;************************************************

	decimal_output proc
   ; this procedure will display a decimal number
   ; input : bx
   ; output : none
   ; uses : main

	   cmp bx, 0                      ; compare bx with 0
	   jge @start                     ; jump to label @start if bx>=0
	   mov ah, 2                      ; set output function
	   mov dl, "-"                    ; set dl='-'
	   int 21h                        ; print the character

	   neg bx                         ; take 2's complement of bx

	   @start:                        ; jump label

	   mov ax, bx                     ; set ax=bx
	   xor cx, cx                     ; clear cx
	   mov bx, 10                     ; set bx=10

	   @repeat:                       ; loop label
	     xor dx, dx                   ; clear dx
	     div bx                       ; divide ax by bx
	     push dx                      ; push dx onto the stack
	     inc cx                       ; increment cx
	     or ax, ax                    ; take or of ax with ax
	   jne @repeat                    ; jump to label @repeat if zf=0

	   mov ah, 2                      ; set output function

	   @display:                      ; loop label
	     pop dx                       ; pop a value from stack to dx
	     or dl, 30h                   ; convert decimal to ascii code
	     int 21h                      ; print a character
	   loop @display                  ; jump to label @display if cx!=0

	   ret                            ; return control to the calling procedure
	 decimal_output endp
	 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


	main proc
		mov ax,@data
		mov ds,ax
		xor bh,bh
		;input prompt
		display prompt_1
		call dec_input
		mov num1,bl
		xor bh,bh
		call dec_input
		mov num2,bl
		xor bh,bh
		xor ah,ah
		mov al,num1
		mul bx
		
		mov bx,ax
		display new_line
		display prompt_2
		call decimal_output

		mov ah,4ch
	 	int 21h

	main endp
end main