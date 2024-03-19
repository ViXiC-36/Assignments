//T1
module top_module( 
    input  [7:0]       in,
    output [7:0]       out
);
    assign out = {in[0], in[1], in[2], in[3], in[4], in[5], in[6], in[7]};

endmodule

//T2.1
module MAX2 (
    input  [7:0]         num1, num2,
    output [7:0]         max
);
    assign max = (num1 > num2) ? num1 : num2;
endmodule

//T2.2
module MAX3 (
    input       [7:0]         num1, num2, num3,
    output reg  [7:0]         max
);
    always @(*) begin
        if (num1 > num2)
            if (num1 > num3)
                max = num1;
            else
                max = num3;
        else
            if (num2 > num3)
                max = num2;
            else
                max = num3;
    end
endmodule

//T2.3????
module MAX3_ (
    input   [7:0]        num1, num2, num3,
    output  [7:0]        max
);

    wire [7:0] temp;

    MAX2 m1(
        .num1   (num1),
        .num2   (num2),
        .max    (temp)
    );

    MAX2 m2(
        .num1   (num3),
        .num2   (temp),
        .max    (max)
    );
endmodule

//T3
module Count4Ones(
    input       [2:0]         in,
    output reg  [1:0]         out
);
    always @(*) begin
        if (in[2] == 1)
            out = 1;
        else
            out = 0;
        if (in[1] == 1)
            out = out + 1;
        if (in[0] == 1)
            out = out + 1;
    end
endmodule

//T4
