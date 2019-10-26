;Write and test a MASM program to add two Hexadecimal Numbers.

.MODEL SMALL
.STACK 100H

.DATA
	NUM1 db ?
	NUM2 db ?
	RESULT db ?
	PROMPT1 db 13,10,"Enter the 1st number: $"
	PROMPT2 db 13,10,"Enter the 2nd number: $"
	PROMPT3 db 13,10,"The result of the addition is: $"

.CODE
	MAIN PROC
		MOV AX, @DATA	;initialize DS
		MOV DS, AX

		LEA DX, PROMPT1	;show num1 prompt
		MOV AH, 9
		INT 21H

		MOV AH, 1
		INT 21H
		SUB AL, 30H
		MOV NUM1, AL	

		LEA DX, PROMPT2	;show num2 prompt
		MOV AH, 9
		INT 21H

		MOV AH, 1
		INT 21H
		SUB AL, 30H
		MOV NUM2, AL

		ADD AL, NUM1
		MOV RESULT, AL

		MOV AH, 0H
		AAA

		ADD AH, 30H
		ADD AL, 30H
		MOV BX, AX

		LEA DX, PROMPT3	;show answer prompt
		MOV AH, 9
		INT 21H

		MOV AH, 2
		MOV DL, BH
		INT 21H
		MOV AH, 2
		MOV DL, BL
		INT 21H

		MOV AH, 4CH		;return control to DOS
	 	INT 21H

	 MAIN ENDP
END MAIN