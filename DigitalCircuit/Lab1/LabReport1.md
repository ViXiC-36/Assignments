# Lab 1 Report

**PB22111599 杨映川**



## 实验内容

- 作业答案


## 作业答案

T1.
>       module top_module( 
>           input  [7:0]       in,
>           output [7:0]       out
>       );
>           assign out = {in[0], in[1], in[2], in[3], in[4], in[5], in[6], in[7]};
>       endmodule

T2.1
>       module MAX2 (
>           input  [7:0]         num1, num2,
>           output [7:0]         max
>       );
>           assign max = (num1 > num2) ? num1 : num2;
>       endmodule
>
T2.2
>       module MAX3 (
>           input       [7:0]         num1, num2, num3,
>           output reg  [7:0]         max
>       );
>           always @(*) begin
>               if (num1 > num2)
>                   if (num1 > num3)
>                       max = num1;
>                   else
>                       max = num3;
>               else
>                   if (num2 > num3)
>                       max = num2;
>                   else
>                       max = num3;
>           end
>       endmodule      
>
T2.3
- 调用两次MAX2模块，并使用名为temp的wire将其连接起来。
>       module MAX2 (
>           input  [7:0]         num1, num2,
>           output [7:0]         max
>       );
>           assign max = (num1 > num2) ? num1 : num2;
>       endmodule
>       
>       module MAX3_ (
>           input   [7:0]        num1, num2, num3,
>           output  [7:0]        max
>       );
>       
>           wire [7:0] temp;
>       
>           MAX2 m1(
>               .num1   (num1),
>               .num2   (num2),
>               .max    (temp)
>           );
>       
>           MAX2 m2(
>               .num1   (num3),
>               .num2   (temp),
>               .max    (max)
>           );
>       endmodule
>
T3.
>       c = 8'b0011_0000
>       d = 8'b0000_0001
>       e = 8'b1100_0011
>       f = 8'b1100_1100
>       g = 8'b0110_0001
>       h = 8'b1111_1110
>       i = 8'b0000_0000
>       j = 8'b1111_0000
>       k = 8'b0100_0011
>       l = 8'b0000_0000

