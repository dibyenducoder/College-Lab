;11. Write and test a program to add and subtract two 16 bit numbers.

.model small
.stack 100h

.data
	prompt_1 db "Enter two numbers :",10,13,"$"
	prompt_2 db "Sum : $"
	prompt_3 db "Difference : $"
	new_line db 10,13,'$'

	num1 dw ?
	num2 dw ?

	;macro to display prompt and print string
	display macro msg
		mov ah,9
		lea dx,msg
		int 21h
	endm

.code

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

	main proc
		mov ax,@data
		mov ds,ax

		;input prompt
		display prompt_1
		call hex_input
		mov num1,bx

		call hex_input
		mov num2,bx
		
		;********************** SUM **************************************
		display prompt_2
		
		mov cx,num1
		add bx,cx

		jnc @display

		carry_disp:
			;display carry
			mov ah,02h
			mov dl,'1'
			int 21h

		@display:
			call hex_output
		;********************** SUM **************************************

		;********************** DIFF **************************************
		display new_line
		display prompt_3
		
		mov bx,num1
		mov cx,num2
		sub bx,cx
		
		call hex_output
		;********************** DIFF **************************************

		mov ah,4ch
		int 21h

	main endp
end main