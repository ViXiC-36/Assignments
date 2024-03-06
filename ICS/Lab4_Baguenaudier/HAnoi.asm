  .ORIG x3000
        ; *** Begin user program code here ***
;=====================main======================== 
LD R6,STACK
LD R0,LETTERc
STR R0,R6,#0
ADD R6,R6,#-1
LD R0,LETTERb
STR R0,R6,#0
ADD R6,R6,#-1
LD R0,LETTERa
STR R0,R6,#0
;把初始数据压入栈中以备调用

LEA R0,Prompt ;output prompt
TRAP x22
;输出“请输入汉诺塔阶数”

TRAP x20 ;input n
;从键盘读入n

LD R1,ASCII
ADD R0,R0,R1
ADD R6,R6,#-1
STR R0,R6,#0
JSR Hanoi
HALT

;=====================function==================== 
Hanoi ADD R6,R6,#-1 ;store return address 
STR R7,R6,#0
ADD R6,R6,#-1 ;push caller's frame pointer
STR R5,R6,#0
ADD R5,R6,#0 ;set new frame pointer
;
LDR R0,R5,#2
ADD R0,R0,#-1
BRz H_BASE

;move(x-1,a,c,b)
LDR R0,R5,#4 ;push b
ADD R6,R6,#-1
STR R0,R6,#0
LDR R0,R5,#5 ;push c
ADD R6,R6,#-1
STR R0,R6,#0
LDR R0,R5,#3 ;push a
ADD R6,R6,#-1
STR R0,R6,#0
LDR R0,R5,#2 ;push x-1
ADD R0,R0,#-1
ADD R6,R6,#-1
STR R0,R6,#0
JSR Hanoi

;output
LEA R0,OUTPUT1
TRAP x22
LDR R0,R5,#3
TRAP x21
LEA R0,OUTPUT2
TRAP x22
LDR R0,R5,#5
TRAP x21
LD R0,Newline
TRAP x21

;move(x-1,b,a,c)
LDR R0,R5,#5 ;push c
ADD R6,R6,#-1
STR R0,R6,#0
LDR R0,R5,#3 ;push a
ADD R6,R6,#-1
STR R0,R6,#0
LDR R0,R5,#4 ;push b
ADD R6,R6,#-1
STR R0,R6,#0
LDR R0,R5,#2 ;push x-1
ADD R0,R0,#-1
ADD R6,R6,#-1
STR R0,R6,#0
JSR Hanoi
BRnzp H_END
;
H_BASE LEA R0,OUTPUT1
TRAP x22
LDR R0,R5,#3
TRAP x21
LEA R0,OUTPUT2
TRAP x22
LDR R0,R5,#5
TRAP x21
LD R0,Newline
TRAP x21
;
H_END LDR R5,R6,#0
ADD R6,R6,#1
LDR R7,R6,#0
ADD R6,R6,#5
RET
;
ASCII .FILL xFFD0
Newline .FILL x000A
STACK .FILL x6000
LETTERa .FILL x0061
LETTERb .FILL x0062
LETTERc .FILL X0063
Prompt .STRINGZ "Please input the number of the Hanoi Tower>" 
OUTPUT1 .STRINGZ "MOVE "
OUTPUT2 .STRINGZ " TO "
.END
