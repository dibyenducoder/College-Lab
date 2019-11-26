.MODEL SMALL
.STACK 100H
.DATA 
  PROMPT1 DB 10,13,'Enter first number : $'
  PROMPT2 DB 10,13,'Enter second number : $'
  PROMPT3 DB 10,13,'Enter third number : $'
  PROMPTG DB 10,13,'GCD = $'
  PROMPTL DB 10,13,'LCM = $'
  NUM1 DW ?
  NUM2 DW ?
  NUM3 DW ?
  G DW ?
  L DW ?
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

    GCD PROC ;GCD(AX,BX) STORED IN BX
      LP:
        CMP AX,BX
        JE EXIT
        JB EXCG

      LP2:
        MOV DX,00H
        DIV BX
        CMP DX,0
        JE EXIT
        MOV AX,DX
        JMP LP

      EXCG:
        XCHG AX,BX
        JMP LP2
      EXIT:
        RET
    GCD ENDP
    
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

      LEA DX, PROMPT3
      MOV AH,9
      INT 21H     

      CALL INPUT
      MOV NUM3,BX

      MOV AX,NUM1
      MOV BX,NUM2
      CALL GCD

      MOV G,BX

      MOV AX,NUM1
      MOV BX,NUM2
      MUL BX
      MOV BX,G
      DIV BX
      MOV L,AX

      MOV AX,G
      MOV BX,NUM3
      CALL GCD
      MOV G,BX
      MOV BX,L
      MOV AX,NUM3
      CALL GCD
      MOV CX,BX
      MOV AX,L
      MOV BX,NUM3
      MUL BX
      DIV CX
      MOV L,AX

      LEA DX, PROMPTG
      MOV AH,9
      INT 21H 
      MOV BX,G
      CALL OUTPUT

      LEA DX, PROMPTL
      MOV AH,9
      INT 21H
      MOV BX,L
      CALL OUTPUT

      MOV AH,4CH
      INT 21H
        
  MAIN ENDP
END MAIN