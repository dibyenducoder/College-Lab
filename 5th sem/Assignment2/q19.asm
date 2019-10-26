;19. Write and test a program to identify the GCD and LCM of three numbers.

.model small
.stack 100h

.data
	prompt_1 db 10,13,"Enter 3 numbers:",10,13,"$"
	prompt_2 db 10,13,"GCD : $"
	prompt_3 db 10,13,"LCM : $"

	num1 dw ?
	num2 dw ?
	num3 dw ?

	gcdn dw ?
	lcmn dw ?

	;macro to display prompt and print string
	display macro msg
		mov ah,9
		lea dx,msg
		int 21h
	endm

.code

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;gcd function;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	gcd proc
	; input: bx,ax
	; output: gcd

	; Assumption: cx is greater than bx
	  up: 
	  	  cmp ax,bx        ;compare the two numbers.
		  je exit          ;if equal, go to exit label.
		  jb excg          ;if first number is below than second,
					   ;go to excg label.
	  up1: 
	  	   mov dx,0h       ;initialize the dx.
		   div bx          ;divide the first number by second number.
		   cmp dx,0        ;compare remainder is zero or not.
		   je exit         ;if zero, jump to exit label.
		   mov ax,dx       ;if non-zero, move remainder to ax.
		   jmp up
		             		;jump to up label.
	  excg:
	  	   xchg ax,bx     ;exchange the remainder and quotient.
		   jmp up1        ;jump to up1.
	  exit:
	  	   mov gcdn,bx     ;store the result in gcd.
		   ret
	gcd endp

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;;;lcm function;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	lcm proc
	; input: bx,ax
	; output: dx
		xor dx,dx
		mul bx	;product of numbers
		div gcdn	;by gcd of numbers
		mov lcmn,ax
		ret
	lcm endp

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

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

		;input
		display prompt_1
		; first number
		call dec_input
		mov num1,bx

		;second
		call dec_input
		mov num2,bx

		;third
		call dec_input
		mov num3,bx			

		; ********************** GCD ************************************
		;find GCD of first two
		mov ax,num1
		mov bx,num2
		call gcd

		; GCD of GCD and third 
		mov ax,num3
		mov bx,gcdn
		call gcd

		;output
		display prompt_2
		mov bx,gcdn
		call decimal_output
		; ********************** GCD ************************************

		; ********************** LCM ************************************
		; find gcd of two
		mov ax,num1
		mov bx,num2
		call gcd
		; find lcm
		mov ax,num1
		mov bx,num2
		call lcm

		; find gcd of two
		mov ax,lcmn
		mov bx,num3
		call gcd
		; find lcm
		mov ax,lcmn
		mov bx,num3
		call lcm

		;output
		display prompt_3
		mov bx,lcmn
		call decimal_output
		; ********************** LCM ************************************
		mov ah,4ch
		int 21h

	main endp
end main