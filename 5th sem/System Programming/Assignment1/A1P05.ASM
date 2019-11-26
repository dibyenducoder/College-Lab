.MODEL SMALL
.STACK 100H

.DATA
  PROMPT1 DB 'Enter a character : $'
  PROMPT2 DB 'The character you entered is : $'
  TERM_PROMPT DB '--Thank you!--$'

.CODE
  MAIN PROC
    MOV AX,@DATA
    MOV DS,AX

    LEA DX, PROMPT1
    MOV AH,9
    INT 21H

    MOV AH,1
    INT 21H

    MOV BL,AL

    MOV AH,2
    MOV DL,0DH
    INT 21H

    MOV DL,0AH
    INT 21H

    LEA DX, PROMPT2
    MOV AH,9
    INT 21H

    MOV AH,2
    MOV DL,BL
    INT 21H

    MOV AH,2
    MOV DL,0DH
    INT 21H

    MOV DL,0AH
    INT 21H

    LEA DX, TERM_PROMPT
    MOV AH,9
    INT 21H

    MOV AH,4CH
    INT 21H
  MAIN ENDP
END MAIN
