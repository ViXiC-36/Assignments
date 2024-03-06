; Unfortunately we have not YET installed Windows or Linux on the LC-3,
; so we are going to have to write some operating system code to enable
; keyboard interrupts. The OS code does three things:
;
;    (1) Initializes the interrupt vector table with the starting
;        address of the interrupt service routine. The keyboard
;        interrupt vector is x80 and the interrupt vector table begins
;        at memory location x0100. The keyboard interrupt service routine
;        begins at x1000. Therefore, we must initialize memory location
;        x0180 with the value x1000.
;    (2) Sets bit 14 of the KBSR to enable interrupts.
;    (3) Pushes a PSR and PC to the system stack so that it can jump
;        to the user program at x3000 using an RTI instruction.

            .ORIG   x800
            ; (1) Initialize interrupt vector table.
            LD      R0, VEC
            LD      R1, ISR
            STR     R1, R0, #0
    
            ; (2) Set bit 14 of KBSR.
            LDI     R0, KBSR
            LD      R1, MASK
            NOT     R1, R1
            AND     R0, R0, R1
            NOT     R1, R1
            ADD     R0, R0, R1
            STI     R0, KBSR
    
            ; (3) Set up system stack to enter user space.
            LD      R0, PSR
            ADD     R6, R6, #-1
            STR     R0, R6, #0
            LD      R0, PC
            ADD     R6, R6, #-1
            STR     R0, R6, #0
            ; Enter user space.
            RTI
        
VEC         .FILL   x0180
ISR         .FILL   x1000
KBSR        .FILL   xFE00
MASK        .FILL   x4000
PSR         .FILL   x8002
PC          .FILL   x3000
            .END


; The user program
            .ORIG   x3000
            ; *** Begin user program code here ***
;            LD      R6, USP                      ;initialize USP, user stack pointer
            AND R4, R4, #0
            ; YOUR CODE HERE

LOOP        JSR DELAY
            LEA R0, BEONHO
            TRAP x22
            BRnzp LOOP
            
            ; DONE
DELAY       ST  R1, SaveR1
            LD  R1, COUNT
REP         ADD R1, R1, #-1
            BRp REP
            LD  R1, SaveR1
            RET
            ; *** End user program code here ***
SaveR1      .FILL   x5000
COUNT       .FILL   x5555
BEONHO      .STRINGZ    "PB22111599 "

            .END



            .ORIG   x3FFF
            ; *** Begin factorial data here ***

FACT_N      .FILL   xFFFF
            ; *** End factorial data here ***
            .END



            .ORIG   x1000
            ; *** Begin interrupt service routine code here ***
            AND R2, R2, #0; FOR TEMP CONSTANT
            AND R3, R3, #0; FOR TRANSMITTING
            AND R4, R4, #0; FOR TRASH
            ; YOUR CODE HERE
            LD R0, NEWLINE
            OUT; \n
            
            GETC ; LOAD N INTO R0
            OUT
            LD  R2, ASCIIN0
            ADD R4, R0, R2    ; n-'0'
            BRn ERROR
            ADD R3, R3, R4
            LD  R2, ASCIIN9     
            ADD R4, R0, R2    ; n-'9'
            BRp ERROR
            LEA R0, OUTRIGHT
            PUTS
            ; RIGHT DESU!
            LD R0, NEWLINE
            OUT; \n
            
            ADD R0, R3, #0
            JSR FACTORIAL; INSIDE THE PROGRAM WILL HALT
ERROR       LEA R0, OUTWRONG
            PUTS
            LD R0, NEWLINE
            OUT; \n
            BRnzp FINISH
            ; DONE
; NOW, N IS IN R3 AND R0
FACTORIAL   ADD R0, R3, #0
            BRp SKIP0
            LEA R0, RES0
            BR  ENDD
SKIP0       ADD R0, R0, #-1
            BRp SKIP1
            LEA R0, RES1
            BR  ENDD
SKIP1       ADD R0, R0, #-1
            BRp SKIP2
            LEA R0, RES2
            BR  ENDD
SKIP2       ADD R0, R0, #-1
            BRp SKIP3
            LEA R0, RES3
            BR  ENDD
SKIP3       ADD R0, R0, #-1
            BRp SKIP4
            LEA R0, RES4
            BR  ENDD
SKIP4       ADD R0, R0, #-1
            BRp SKIP5
            ST  R3, FACT
            LEA R0, RES5
            BR  ENDD
SKIP5       ADD R0, R0, #-1
            BRp SKIP6
            LEA R0, RES6
            BR  ENDD
SKIP6       ADD R0, R0, #-1
            BRp SKIP7
            LEA R0, RES7
            BR  ENDD
SKIP7       ADD R0, R0, #-1
            BRp SKIP8
            LEA R0, RES8
            BR  ENDD
SKIP8       LEA R0, RES9

ENDD        PUTS
            LD  R2, FACT
            STR R3, R2, #0
            LD  R0, NEWLINE
            OUT; \n
            HALT
            
            RET
           
FINISH      RTI
            ; *** End interrupt service routine code here ***
NEWLINE     .FILL   x000A
ASCIIN0     .FILL   xFFD0; -'0'
ASCIIN9     .FILL   xFFC6; -'9'
FACT        .FILL   x3FFF

OUTWRONG    .STRINGZ    " is not a decimal digit. "
OUTRIGHT    .STRINGZ    " is a decimal digit. "
RES0        .STRINGZ    "0! = 1."
RES1        .STRINGZ    "1! = 1."
RES2        .STRINGZ    "2! = 2."         
RES3        .STRINGZ    "3! = 6."         
RES4        .STRINGZ    "4! = 24."         
RES5        .STRINGZ    "5! = 120."         
RES6        .STRINGZ    "6! = 720."         
RES7        .STRINGZ    "7! = 5040."         
RES8        .STRINGZ    "8! is too large for LC-3."         
RES9        .STRINGZ    "9! is too large for LC-3."         
            .END