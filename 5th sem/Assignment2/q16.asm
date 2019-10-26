;16. Write and test a program to divide a 16 bit number by a 8 bit number.

.model small
.stack 100h

.data
	prompt_1 db 10,13,"Enter 16 bit number: $"
	prompt_2 db 10,13,"Enter 8 bit number: $"
	prompt_3 db 10,13,"Quotient : $"
	prompt_4 db 10,13,"Remainder : $"

	num1 dw ?

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
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	
	main proc

		mov ax,@data
		mov ds,ax

		;input
		display prompt_1
		call hex_input

		mov num1,bx

		display prompt_2
		call hex_input

		mov ax,num1
		xor dx,dx
		div bx

		;output
		mov bx,ax
		mov num1,dx

		display prompt_3
		pushall
		call hex_output
		popall

		mov bx,num1

		display prompt_4
		pushall
		call hex_output
		popall

		mov ah,4ch
		int 21h

	main endp
end main