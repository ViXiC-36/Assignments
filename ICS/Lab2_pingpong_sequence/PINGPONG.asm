        .ORIG x3000
; INITIALIZATION
        AND R0, R0, #0
        ADD R0, R0, #3              ; R0 FOR RESULT
        AND R1, R1, #0              ; R1 FOR SIGN, 0+, !0-
        ADD R5, R1, #0              ; R5 FOR TEMP OF FLIPPED SIGN
        ADD R3, R0, #2              ; R3 FOR CONSTANT 2
        LDI R2, NVAR                ; R2 FOR number variable
        LD  R6, MODULO              ; R6 STORING x0FFF
; CALCULATION                       ; R4 FOR PROCESS ZONE
        ADD R2, R2, #-1             
        BRz ENDALL                  ; WHEN N == 1
LOOP    AND R3, R3, #0
        ADD R3, R3, #2
        ADD R0, R0, R0              ; R0 *= 2
        ADD R1, R1, #0
        BRz PLUS
        AND R3, R3, #0
        ADD R3, R3, #-2             ; R3 = -2
PLUS    ADD R0, R0, R3              ; R0 += R3
; MODULO
        AND R0, R0, R6              ; R0 %= 4096
; LAST DIGIT IS 8? 
        ADD R4, R0, #10
        ADD R4, R4, #-8             ; -8
        ADD R4, R4, #-10
        BRp #-2
        ADD R4, R4, #0
        BRn DONEFLP
        NOT R5, R1
; MULYIPLE OF 8? 
DONEFLP AND R4, R0, #7              ; MAINTAIN ONLY THE LAST 3 DIGITS
        BRnp DONEFLX
        NOT R5, R1
DONEFLX ADD R1, R5, #0              ; UPDATE THE SIGN
        ADD R2, R2, #-1
        BRp LOOP
ENDALL  STI R0, RESULT              ; LOAD THE RESULT IN x3103
        TRAP x25
        
NVAR    .FILL x3102
RESULT  .FILL x3103
MODULO  .FILL X0FFF
.END