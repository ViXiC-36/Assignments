.ORIG x3000     
AND R1, R1, x0
AND R4, R4, x0
ADD R4, R4, #10
LEA R2, x0FC
LOOP LDR R3, R2, x0
ADD R2, R2, #1      ;INCREMENT THE POINTER
ADD R1, R1, R3      ;ADD THE NEXT NUMBER TO THE PRESENT SUM
ADD R4, R4, #-1     ;DECREMENT THE COUNTER
BRP LOOP            ;KEEP IT GOING IF TEH COUNTER ISN'T 0
HALT
.END