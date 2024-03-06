        .ORIG x3000
        ; R0              input & output info
        LD  R1, TABLE   ; LOCATION OF THE TABLE OF INPUT
        AND R2, R2, #0  ; COUNTER FOR THE TIMES OF ATTEMPTS
        AND R3, R3, #0  ; COUNTER FOR THE LENGTH OF INPUT
        AND R4, R4, #0  ; TRASH
        AND R5, R5, #0  ; LOAD A NUMBER
        
START   AND R2, R2, #0
        ADD R2, R2, #3
        LEA R0, WELCOME
        TRAP x22
        
LOOP    TRAP x23
        LD  R4, NEG_W
        ADD R4, R4, R0
        BRz WITHDRAW
        LEA R0, TYPO
        TRAP x22
        BRnzp LOOP
        
WITHDRAW LEA R0, IN_PROMPT 
        TRAP x22
        AND R3, R3, #0
        ADD R3, R3, #10
        LD  R1, TABLE
        
INPUTTING TRAP x23
        STR R0, R1, #0
        ADD R1, R1, #1  ; LOAD THE INPUT IN THE TABLE
        LD  R4, NEG_Y
        ADD R4, R4, R0
        BRz SUBMITTED
        ADD R3, R3, #-1
        BRnzp INPUTTING
        
SUBMITTED ADD R3, R3, #0
        BRz MATCH       ; START EXAMINING WHEN THE LENGTH IS 10
        BRnzp INCORRECT
MATCH   LD  R1, TABLE
        ; COMPARE RESPECTIVELY
        LDR R5, R1, #0
        ADD R1, R1, #1
        LD  R4, NEG_P
        ADD R4, R5, R4
        BRnp INCORRECT
        LDR R5, R1, #0
        ADD R1, R1, #1
        LD  R4, NEG_B
        ADD R4, R5, R4
        BRnp INCORRECT
        LDR R5, R1, #0
        ADD R1, R1, #1
        LD  R4, NEG_2
        ADD R4, R5, R4
        BRnp INCORRECT
        LDR R5, R1, #0
        ADD R1, R1, #1
        LD  R4, NEG_2
        ADD R4, R5, R4
        BRnp INCORRECT
        LDR R5, R1, #0
        ADD R1, R1, #1
        LD  R4, NEG_1
        ADD R4, R5, R4
        BRnp INCORRECT
        LDR R5, R1, #0
        ADD R1, R1, #1
        LD  R4, NEG_1
        ADD R4, R5, R4
        BRnp INCORRECT
        LDR R5, R1, #0
        ADD R1, R1, #1
        LD  R4, NEG_1
        ADD R4, R5, R4
        BRnp INCORRECT
        LDR R5, R1, #0
        ADD R1, R1, #1
        LD  R4, NEG_5
        ADD R4, R5, R4
        BRnp INCORRECT
        LDR R5, R1, #0
        ADD R1, R1, #1
        LD  R4, NEG_9
        ADD R4, R5, R4
        BRnp INCORRECT
        LDR R5, R1, #0
        ADD R1, R1, #1
        LD  R4, NEG_9
        ADD R4, R5, R4
        BRnp INCORRECT
        BRnzp SUCCESS
        
INCORRECT LEA R0, WRONG
        TRAP x22
        AND R3, R3, #0
        ADD R3, R3, #10
        LD  R1, TABLE
        ADD R2, R2, #-1
        BRz ENDALL
        ADD R0, R2, #0
        LD  R5, ASCII
        ADD R0, R0, R5
        TRAP x21
        LEA R0, LEFT
        TRAP x22
        BRnzp INPUTTING
        
ENDALL  LEA R0, FAIL
        TRAP x22
        BRnzp START
        
SUCCESS LEA R0, SUC
        TRAP x22
        HALT
        
TABLE   .FILL       x4000
NEG_W   .FILL       xFFA9
NEG_Y   .FILL       xFFA7
ASCII   .FILL       x0030
NEG_P   .FILL       xFFB0
NEG_B   .FILL       xFFBE
NEG_2   .FILL       xFFCE
NEG_1   .FILL       xFFCF
NEG_5   .FILL       xFFCB
NEG_9   .FILL       xFFC7
WELCOME .STRINGZ    "Welcome to the bank system! Type 'W' to withdraw some fund. "
TYPO    .STRINGZ    "You didn't enter 'W', try again! "
FAIL    .STRINGZ    "Fails. "
IN_PROMPT .STRINGZ  "Please input your password: "
WRONG   .STRINGZ    "Incorrect password! "
LEFT    .STRINGZ    " attempt(s) remain. "
SUC     .STRINGZ    "Success! "
.END