;17. Write and test a program to Print Fibonacci series up to 10 terms.

.model small
.stack 100h

.data
	prompt db "The fibonacci series upto 10 terms is: $"
	new_line db 10,13,"$"
	space db " $"

	
	f1 dw 1
	f2 dw 1
	f3 dw ?

	;macro to display prompt and print string
	display macro msg
		mov ah,9
		lea dx,msg
		int 21h
	endm

	;macro to push all registers into stack
	pushall macro
		push ax
		push bx
		push cx
		push dx
	endm

	;macro to pop all registers from stack
	popall macro
		pop dx
		pop cx
		pop bx
		pop ax
	endm

.code

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

		mov bx,1
		mov dx,1
		display prompt
		display new_line

		pushall
		call decimal_output
		display space
		popall

		pushall
		call decimal_output
		display space
		popall

		mov bx,1
		mov dx,1
		mov cx,8

		@loop:
			mov f1,bx	
			mov f2,dx
			add bx,dx
			mov f3,bx	;f3=f1+f2

			pushall
			call decimal_output
			display space
			popall

			mov bx,f2	;f1=f2
			mov dx,f3	;f2=f3

		loop @loop

		mov ah,4ch
		int 21h

	main endp
end main