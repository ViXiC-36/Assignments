`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/26 13:18:38
// Design Name: 
// Module Name: ccounterr
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


module ccounterr #(
    parameter   MAX_VALUE = 8'd13,
    parameter   MIN_VALUE = 8'd10
)(
    input                   clk,
    input                   rst,
    input                   enable,
    output                  out
);

reg [7:0] counter;
always @(posedge clk) begin
    if (rst)
        counter <= 0;
    else 
        begin
        if (enable) begin
            if (counter == 0)
                counter <= MIN_VALUE;
            else if (counter >= MAX_VALUE)
                counter <= MIN_VALUE;
            else
                counter <= counter + 8'b1; 
        end
        else
            counter <= 0;
    end
end

assign out = (counter == MAX_VALUE);
endmodule

module q4_tb();
reg clk, rst, en;
wire out_PB;
initial begin
    clk = 0; rst = 1; en = 0;
    #10;
    rst = 0;
    #10;
    en = 1;
    #20;
    en = 0;
    #20;
    en = 1;
    #20;
    rst = 1;
    #20;
    rst = 0;
    #200;
    en = 0;
end
always #5 clk = ~clk;
ccounterr #(
    .MIN_VALUE(8'd10), 
    .MAX_VALUE(8'd13)
) ccounterr (
    .clk(clk),
    .rst(rst),
    .enable(en),
    .out(out_PB)
);
endmodule

