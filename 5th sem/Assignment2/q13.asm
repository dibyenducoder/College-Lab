;13.Write and test a program to print pairs of even numbers where the summation of the numbers in each pair is 100.

.model small
.stack 100h


.data
	new_line db 10,13,'$'
	comma db ' , $'

	tempb dw ?
	tempc dw ?

	;macro to display prompt and print string
	display macro msg
		mov ah,9
		lea dx,msg
		int 21h
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

		mov bx,0
		mov cx,100

		@print_loop:
			mov tempb,bx
			mov tempc,cx

			call decimal_output
			display comma

			mov bx,tempc
			call decimal_output
			display new_line

			mov bx,tempb
			mov cx,tempc

			inc bx
			inc bx

			dec cx
			dec cx

			cmp bx,52
		jl @print_loop
		
		mov ah,4ch
	 	int 21h

	main endp
end main