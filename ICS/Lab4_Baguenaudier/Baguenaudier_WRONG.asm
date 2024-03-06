        .ORIG x3000
        
        LD  R6, STACK   ; 
        LD  R0, NUM     ; NUMBER OF RINGS
        AND R1, R1, #0  ; STATE
        AND R2, R2, #0  ; TEMP BIT
        AND R4, R4, #0  ; TEMP COUNT
        JSR REMOVE
        HALT
        
REMOVE  ADD R6, R6, #1  ;STACK LOCATION
; ******EXIT?************
        ADD R4, R0, #-1
        BRz 
        
        
; ******R(i - 2)*********        
        ADD R0, R0, #-2
        JSR REMOVE      ; R(i - 2)
; ******r(i)*************
        ADD R6, R6, #1
        ADD R0, R0, #2  ; r(i)
        AND R2, R2, #0
        ADD R2, R2, #1  ; R2 <- 1
        ADD R4, R0, #0  ; COUNT <- R0
        BRzp BIT_OK
        ADD R2, R2, R2  ; R2 << 1
        ADD R4, R4, #-1 ; COUNT--
        BRz BIT_OK
BIT_OK  ADD R1, R1, R2  ; DONE r(i)
        STR R1, R6, #0  ;
; ******P(i - 2)*********

; ******R(i - 1)*********





STACK   .FILL x4000
NUM     .FILL x3100