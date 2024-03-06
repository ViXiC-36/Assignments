        .ORIG x3000             ; STARTING AT x3000
        LDI R0, ORI             ; ORIGINAL NUMBER
        AND R2, R2, #0          ; CLEAR R2 TO BE A COUNTER
        AND R3, R3, #0          ; CLEAR R3 TO RECORD THE NUMBER OF 1'S
        AND R4, R4, #0          ; CLEAR R4 FOR A TEMPORARY VALUE
        AND R5, R5, #0          ; CLEAR R5 AS AN IMMEDIATE NUMBER
; R0: SIGN, R1: ORIGINAL, R2: COUNTER, 
; R3: NUMBER OF 0'S, R4: TEMP VALUE, R5: IMME NUM
; ODD OR EVEN?   
        LDI R1, ORI             ; ORIGINAL NUMBER
        AND R0, R0, #1          ; 1 IF ODD, 0 IF EVEN IN R0
        BRNP #2                 ; SKIP WHEN ODD(1)
        NOT R1, R1              ; EVEN NUMBER'S 1'S COMPLEMENT
        ADD R1, R1, #1          ; EVEN NUMBER'S 2'S COMPLEMENT
        ADD R5, R5, #1          ; IMMEDIATE NUMBER 
        ADD R2, R2, #15
        ADD R2, R2, #1          ; LOOP FOR 16 TIMES
; BITWISELY COMPARE TO COUNT 0'S
LOOP    AND R4, R1, R5          ; BITEWISE AND
        BRNP #1                 ; NON 0?
        ADD R3, R3, #1          ; 0, 0_NUM++
        ADD R5, R5, R5          ; 1, R5 MOVE 1 DIGIT TO THE LEFT
        ADD R2, R2, #-1         ; COUNTER--
        BRP LOOP                ; LOOP WHEN COUNTER ISN'T 0
; COUNTING COMPLETED
        LDI R2, STU_NUM         ; R2 IS 0 TO PUT STU_NUM
        ADD R3, R3, R2          ; RES + STU_NUM
        STI R3, RES
        HALT
ORI     .FILL x3100             ; ORIGINAL NUMBER
STU_NUM .FILL x3101             ; STUNUM'S LOC
RES     .FILL x3102             ; FINAL RESULT
        .END