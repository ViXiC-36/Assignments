`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/26 14:36:10
// Design Name: 
// Module Name: lab2Q3
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module lab2Q3();
    reg         clk;
    reg         a;
    reg         b;
    reg [7:0]   c;

    initial begin
        clk = 1;
        a = 1;
        b = 0;    
        c = 8'b0;
        c = c + 1;
        #20;
        b = ~b;
        #10;
        b = ~b;
        #10;
        c = c + 1;
        #20;
        a = ~a;
        b = ~b;
        #20;
        a = ~a;
        c = c + 1;
        #40;
        a = ~a;
        b = ~b;
        #10;
        b = ~b;
        #10;
        a =~a;
        c = c + 1;
        #20;
        b = ~b;
    end
    always #10 clk = ~clk;

endmodule
