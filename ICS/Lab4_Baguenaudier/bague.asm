;R(i) = R(i - 2) + r(i) + P(i - 2) + R(i - 1)
;P(i) = P(i - 1) + R(i - 2) + p(i) + P(i - 2)
;
;
    .ORIG x3000
    
    LD  R6, STACK   ; STACK POINTER OF STATES
    LDI R0, NUM     ; NUMBER OF RINGS
    AND R1, R1, #0  ; STATE
    AND R2, R2, #0  ; TEMP BIT
    AND R4, R4, #0  ; TEMP COUNT
    AND R3, R3, #0  ; ALL THE TIME 0 INSIDE
    STI R3, NUM
    LD  R5, ADDRESS ; STACK POINTER OF RETURN ADDRESSES
    JSR BAGUE_R
    STI R0, NUM
    HALT
        
BAGUE_R
; ***PUSH THE RETURN ADDRESS***
    ADD R5, R5, #1
    STR R7, R5, #0
; ***R(i - 2)***
    ADD R4, R0, #-2
    BRnz SKIPI      ; if(n>2) B_R(n-2)
    ADD R0, R0, #-2
    JSR BAGUE_R
    ADD R0, R0, #2
SKIPI
; ***r(i)***
    JSR REMOVE_ONE
; ***P(i - 2)***  
    ADD R4, R0, #-2
    BRnz SKIPII
    ADD R0, R0, #-2
    JSR BAGUE_P
    ADD R0, R0, #2
SKIPII
; ***R(i - 1)***    
    ADD R4, R0, #-1
    BRnz SKIPIII
    ADD R0, R0, #-1
    JSR BAGUE_R
    ADD R0, R0, #1
SKIPIII
; ***POP THE RETURN ADDRESS***
    LDR R7, R5, #0
    ADD R5, R5, #-1
    RET
    
    
BAGUE_P
; ***PUSH THE RETURN ADDRESS***
    ADD R5, R5, #1
    STR R7, R5, #0
; ***P(i - 1)***
    ADD R4, R0, #-1
    BRnz SKIPIV
    ADD R0, R0, #-1
    JSR BAGUE_P
    ADD R0, R0, #1
SKIPIV
; ***R(i - 2)***
    ADD R4, R0, #-2
    BRnz SKIPV
    ADD R0, R0, #-2
    JSR BAGUE_R
    ADD R0, R0, #2
SKIPV
; ***p(i)***
    JSR PUT_ONE
; ***P(i - 2)***
    ADD R4, R0, #-2
    BRnz SKIPVI
    ADD R0, R0, #-2
    JSR BAGUE_P
    ADD R0, R0, #2
SKIPVI
; ***POP THE RETURN ADDRESS***
    LDR R7, R5, #0
    ADD R5, R5, #-1
    RET

REMOVE_ONE
    ADD R4, R0, #0
    BRz NOTHING
    ADD R2, R3, #1  ; LET R2 BE 1
    ADD R4, R0, #-1 ; ARGUMENT N
    BRz BIT_OK      ; n
L1  ADD R2, R2, R2  ; R2 << 1
    ADD R4, R4, #-1 ; COUNT--
    BRp L1
BIT_OK  ; GET THE BIT IN R2
    LDR R1, R6, #0  ; POP THE PRESENT STATE
    ADD R6, R6, #1  ; STACK++
    ADD R1, R2, R1  ; UPDATE THE STATE
    STR R1, R6, #0  ; PUSH THE UPDATED
NOTHING
RET

PUT_ONE
    ADD R4, R0, #0
    BRz NOTHINGG
    ADD R2, R3, #1  ; LET R2 BE 1
    ADD R4, R0, #-1 ; ARGUMENT N
    BRnz BIT_OK2
L2  ADD R2, R2, R2  ; R2 << 1
    ADD R4, R4, #-1 ; COUNT--
    BRp L2
BIT_OK2  ; GET THE BIT IN R2
    NOT R2, R2
    LDR R1, R6, #0  ; POP THE PRESENT STATE
    ADD R6, R6, #1  ; STACK++
    AND R1, R2, R1  ; UPDATE THE STATE
    STR R1, R6, #0  ; PUSH THE UPDATED
NOTHINGG
RET

STACK   .FILL x3100
NUM     .FILL x3100
ADDRESS .FILL x4000
.END