        .ORIG x3000
; INITIALIZATION
        AND R0, R0, #0      ; R0 TO LOAD THE 1ST ADDRESS
        AND R2, R2, #0      ; R2 TO LOAD THE 2ND ADDRESS
        
        AND R4, R4, #0      ; R4 TO LOAD THE DIFFERENCE
        AND R1, R1, #0      ; R1 TO LOAD THE 1ST CHARACTER
        AND R3, R3, #0      ; R3 TO LOAD THE 2ND CHARACTER
        AND R5, R5, #0      ; R5 TO LOAD MINUS R3
; 
        LD  R0, S1_ADDR
        LD  R2, S2_ADDR
        
LOOP    LDR R1, R0, #0
        LDR R3, R2, #0
        
        NOT R5, R3
        ADD R5, R5, #1      ; GET THE MINUS OF R3
        ADD R4, R1, R5      ; GET THE DIFFERENCE
        BRnp ENDALL
        
        ADD R1, R1, #0
        BRz ENDALL
        ADD R3, R3, #0
        BRz ENDALL
        
        ADD R0, R0, #1
        ADD R2, R2, #1
        BRnzp LOOP
        
ENDALL  STI R4, RESULT
        HALT
        
S1_ADDR .FILL x3100         ; ADDRESS OF THE 1ST STRING
S2_ADDR .FILL x3200         ; ADDRESS OF THE 2ND STRING
RESULT  .FILL x3300
        .END
        
        .ORIG x3100
S1      .STRINGZ "DsTA"
        .END
        
        .ORIG x3200
S2      .STRINGZ "DsTAs"
        .END