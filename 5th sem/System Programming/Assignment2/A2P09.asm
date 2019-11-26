.MODEL SMALL
.STACK 100H

.DATA
	PROMPT1 DB 'Enter number of elements : $'
	PROMPT2 DB 'Enter elements :',0DH,0AH,'$'
	PROMPT3 DB 'Enter number to be searched : $'
	PROMPTF DB 'Element found at position $'
	PROMPTNF DB 'Element not found $'
	n_line DB 0DH,0AH,"$"
	NUM DW ?
	NUM2 DW ?
	ARR DW 50 DUP(?)
	MAX DW ?
	SMIN DW ?

.CODE
	MAIN PROC
		MOV AX,@DATA
		MOV DS,AX

		LEA DX, PROMPT1
		MOV AH,9
		INT 21H

		XOR BX,BX
		MOV CL,4

		MOV AH,1
		INT 21H

		INPUT1:
			CMP AL,0DH
			JE LINE1


			CMP AL,39h
			JG LETTER1

			AND AL,0FH
			JMP SHIFT1

		LETTER1:
			SUB AL,37H

		SHIFT1:
			SHL BX,CL
			OR  BL,AL

			INT 21h
			JMP INPUT1
		LINE1:
			LEA SI,ARR
			MOV NUM,BX
			MOV CX,BX

			LEA DX, PROMPT2
			MOV AH,9
			INT 21H

		@ARR_INPUT:
			XOR DX,DX
			MOV AH,1
			INT 21H

		INPUT2:
			CMP AL,0DH
			JE LINE2

			CMP AL,39h
			JG LETTER2

			AND AL,0FH
			JMP SHIFT2

		LETTER2:
			SUB AL,37H

		SHIFT2:
			SHL DX,CL
			OR  DL,AL

			INT 21h
			JMP INPUT2
		LINE2:
			MOV [SI],DX
			ADD SI,2
			LOOP @ARR_INPUT
			
		LEA DX, PROMPT3
		MOV AH,9
		INT 21H
		
		XOR BX,BX
		MOV CL,4

		MOV AH,1
		INT 21H
			
		INPUT3:
			CMP AL,0DH
			JE LINE3


			CMP AL,39h
			JG LETTER3

			AND AL,0FH
			JMP SHIFT3

		LETTER3:
			SUB AL,37H

		SHIFT3:
			SHL BX,CL
			OR  BL,AL

			INT 21h
			JMP INPUT3
		LINE3:
			LEA SI,ARR
			MOV NUM2,BX
			MOV CL,00H
			MOV DX,NUM2

		@SEARCH:
			CMP DX,WORD PTR[SI]
			JE @FOUND
			ADD SI,2
			INC CL
			CMP CL,NUM
			JNE @SEARCH
			LEA DX,PROMPTNF
			MOV AH,9
			INT 21H
			JMP @EXIT

		@FOUND:
			INC CL
			LEA DX,PROMPTF
			MOV AH,9
			INT 21H
			MOV AH,2
			ADD CL,'0'
			MOV DL,CL
			INT 21H
			JMP @EXIT

		@EXIT:
			MOV AH,4CH
			INT 21H
	MAIN ENDP
END MAIN
			