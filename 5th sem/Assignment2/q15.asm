;15. Write and test a program to Convert Binary digit to Hex digit and vice versa.

.model small
.stack 100h

.data

	prompt_0 DB 10,13,10,13,'%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$	'
	prompt_1 DB 10,13,'Enter B for binary-hex conversion, H for vice-versa,anyother key for quit : $'
	prompt_2 DB 10,13,'Enter the Binary Number : $'
	prompt_3 DB 10,13,'Enter the Hexadecimal Number : $'
	prompt_4 DB 10,13,'The converted Binary Number is : $'
	prompt_5 DB 10,13,'The converted Hexadecimal Number is : $'

	display macro msg
		mov ah,9
		lea dx,msg
		int 21h
	endm

	ch_input macro 
		mov ah,1
		int 21h
	endm


.code
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;;Binary Input;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	bin_input proc
		xor bx,bx
		xor cx,cx

		@binput:
		mov ah,1
		int 21h

		cmp al,13
		je @bend

		sub ax,30h
		shl bx,1
		or bl,al
		jmp @binput

		@bend:
		ret
	bin_input endp
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;Binary Output;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	bin_output proc
		mov ax, bx                     	; set ax=bx
		xor cx, cx                     	; clear cx
		mov bx, 2                     	; set bx=2

	   	@brepeat:                       	; loop label
		xor dx, dx                   	; clear dx
		div bx                       	; divide ax by bx
		push dx                      	; push dx onto the stack
		inc cx                       	; increment cx
		or ax, ax                    	; take or of ax with ax
	   	jne @brepeat                    	; jump to label @repeat if zf=0

	   	mov ah, 2                      	; set output function

	   	@bdisplay:                      	; loop label
		pop dx                       	; pop a value from stack to dx
		or dl, 30h                   	; convert decimal to ascii code
		int 21h                      	; print a character
	   	loop @bdisplay                  	; jump to label @display if cx!=0

	   	ret      
	bin_output endp
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;Hex input;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	hex_input proc
		; output: bx
		

		xor bx,bx

		mov ah,01h
		int 21h

		cmp al,0dh
		je skip

		input:
			xor ah,ah
			cmp ax,'A'
			jge in_letter
			sub ax,'0'
			jmp shift
			in_letter:
				sub ax,55
			shift:	
				shl bx,1
				shl bx,1
				shl bx,1
				shl bx,1

			or bx,ax

			; take input
			mov ah,01h
			int 21h

			cmp al,0dh
			jne input

		skip:
			ret

	hex_input endp
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;Hex output;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	hex_output proc
		; input: bx
		
		mov ah,02h
		mov cx,0

		output:
			mov dx,bx
			and dx,0fh
			cmp dx,10
			jge out_letter
			add dx,'0'
			jmp line
		out_letter:
				add dx,55
		line:
			push dx
			inc cx

			shr bx,1
			shr bx,1
			shr bx,1
			shr bx,1

		jnz output

		mov cx,cx
		display_loop:
			pop dx
			int 21h
		loop display_loop

		ret
	hex_output endp
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	main proc
		mov ax,@data
		mov ds,ax

		@start:
		display prompt_0
		display prompt_1

		ch_input

		cmp al,'H'
		je @hex2bin
		cmp al,'B'
		je @bin2hex
		jmp @main_exit

		@bin2hex:
		display prompt_2
		call bin_input
		display prompt_5
		call hex_output
		jmp @start

		@hex2bin:
		display prompt_3
		call hex_input
		display prompt_4
		call bin_output
		jmp @start

		@main_exit:
		mov ah,4ch
	 	int 21h

	main endp
end main