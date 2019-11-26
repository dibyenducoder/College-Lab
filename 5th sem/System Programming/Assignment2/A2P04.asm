.MODEL SMALL
.STACK 100H
.DATA 
  PROMPT1 DB 10,13,'Enter first number : $'
  PROMPT2 DB 10,13,'Enter second number : $'
  PROMPTP DB 10,13,'Product = $'
  NUM1 DW ?
  NUM2 DW ?
  n_line DB 0DH,0AH,"$"

.CODE

  INPUT PROC ;OUTPUT: IN BX

     XOR BX,BX
     MOV CL,4  
     MOV AH,1
     INT 21h
      
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
          RET
    INPUT ENDP

    OUTPUT PROC
      MOV CL,4
      MOV CH,BH
      SHR CH,CL
      AND CH,0FH 
      CMP CH,10
      ADD CH,'0'
      CMP CH,':'
      JL P1
      ADD CH,7

      P1:
        MOV DL,CH
        MOV AH,2
        INT 21H

        MOV CH,BH
        AND CH,0FH
        CMP CH,10
        ADD CH,'0'
        CMP CH,':'
        JL P2
        ADD CH,7
      
      P2:
        MOV DL,CH
        MOV AH,2
        INT 21H

        MOV CH,BL
        SHR CH,CL
        AND CH,0FH
        CMP CH,10
        ADD CH,'0'
        CMP CH,':'
        JL P3
        ADD CH,7
      P3:
        MOV DL,CH
        MOV AH,2
        INT 21H

        MOV CH,BL
        AND CH,0FH
        CMP CH,10
        ADD CH,'0'
        CMP CH,':'
        JL P4
        ADD CH,7
      P4:
        MOV DL,CH
        MOV AH,2
        INT 21H

        JMP QUIT
      PC1:
        MOV DL,'1'
        MOV AH,2
        INT 21h
        JMP OUTPUT
      QUIT:
        RET
    OUTPUT ENDP

     MAIN PROC
      MOV AX,@DATA
      MOV DS,AX        
      
      LEA DX, PROMPT1
      MOV AH,9
      INT 21H

      CALL INPUT
      MOV NUM1,BX

      LEA DX, PROMPT2
      MOV AH,9
      INT 21H
      
      CALL INPUT
      MOV NUM2,BX

      LEA DX, PROMPTP
      MOV AH,9
      INT 21H

      MOV AX,BX

      PROD:
          MOV BX,NUM1
          MUL BX
          JNC OP
          MOV BX,AX
          MOV DL,49
          MOV AH,2
          INT 21H
          MOV AX,BX
      OP:
          MOV BX,AX
          CALL OUTPUT

      MOV AH,4CH
      INT 21H
        
  MAIN ENDP
END MAIN