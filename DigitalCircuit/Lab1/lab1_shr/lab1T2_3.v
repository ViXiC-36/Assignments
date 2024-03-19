module MAX2 (
    input  [7:0]         num1, num2,
    output [7:0]         max
);
    assign max = (num1 > num2) ? num1 : num2;
endmodule

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