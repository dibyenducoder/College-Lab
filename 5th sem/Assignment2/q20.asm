;20. Write and test a program to Implement Linear search.

.model medium
.stack 100h

.data
	prompt_1 	DB 10,13,'Enter the number of elements : $'
	prompt_2 	DB 10,13,'Enter the array elements : ',10,13,'$'
	prompt_3 	DB 10,13,'Enter the element to be searched is : $'
	prompt_4	DB 10,13,'The position of the element is : $'
	prompt_5	DB 'Not found $'

	index			dw 0
	count			dw ?
	array			dw 50 DUP(' ')
	search_element	dw ?

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

		display prompt_1
		call dec_input
		mov count,bx

		display prompt_2
		mov si,offset array
		mov index,0000h
		@input_loop:
			call dec_input
			mov [ si ],bx
			add si,2
			inc index

			mov dx,index
			cmp dx,count
			jne @input_loop

		display prompt_3
		call dec_input
		mov search_element,bx

		display prompt_4

		mov cx,count
		mov si,offset array
		mov index,0000h
		@search_loop:
			mov dx,[ si ]
			cmp dx,search_element
			je @found
			add si,2
			inc index
			loop @search_loop
		jmp @not_found

		@found:
		mov bx,index
		call decimal_output
		jmp @main_exit

		@not_found:
		display prompt_5

		@main_exit:
		mov ah,4ch
	 	int 21h
	 main endp
end main