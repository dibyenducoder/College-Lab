.MODEL LARGE
.STACK 100H

.DATA
	PROMPT DB 'The pairs are : ',0DH,0AH,'$'
	P DW ?
	Q DW ?
	
.CODE
	DECIMAL_OUTPUT PROC
		; this procedure will display a decimal number
		; input : BX
		; output : none
		; uses : MAIN

		CMP BX, 0                      ; compare BX with 0
		JGE START                     ; jump to label @START if BX>=0
		MOV AH, 2                      ; set output function
		MOV DL, "-"                    ; set DL='-'
		INT 21H                        ; print the character
		NEG BX                         ; take 2's complement of BX
		START:                        ; jump label
		MOV AX, BX                     ; set AX=BX
		XOR CX, CX                     ; clear CX
		MOV BX, 10                     ; set BX=10
		RPT:                       ; loop label
		 XOR DX, DX                   ; clear DX
		 DIV BX                       ; divide AX by BX
		 PUSH DX                      ; push DX onto the STACK
		 INC CX                       ; increment CX
		 OR AX, AX                    ; take OR of Ax with AX
		JNE RPT                    ; jump to label @REPEAT if ZF=0
		MOV AH, 2                      ; set output function
		DISPLAY:                      ; loop label
		 POP DX                       ; pop a value from STACK to DX
		 OR DL, 30H                   ; convert decimal to ascii code
		 INT 21H                      ; print a character
		LOOP DISPLAY                  ; jump to label @DISPLAY if CX!=0
		RET                            ; return control to the calling procedure
	DECIMAL_OUTPUT ENDP
	MAIN PROC
		MOV AX,@DATA
		MOV DS,AX		
		LEA DX,PROMPT
		MOV AH,9
		INT 21H		
		MOV BX,2
		MOV CX,98		
		LP:
			MOV P,BX
			MOV Q,CX
			CALL DECIMAL_OUTPUT
			MOV DL,32
			MOV AH,2
			INT 21H
			MOV BX,Q
			CALL DECIMAL_OUTPUT
			MOV AH,2
			MOV DL,0DH
			INT 21H
			MOV DL,0AH
			INT 21H
			MOV BX,P
			MOV CX,Q
			INC BX
			INC BX
			DEC CX
			DEC CX
			CMP BX,52
			JNE LP			
		MOV AH,4CH
		INT 21H
	MAIN ENDP
END MAIN