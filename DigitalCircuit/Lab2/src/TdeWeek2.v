module top_module (
    input                       cpu_overheated,
    output  reg                 shut_off_computer,
    input                       arrived,
    input                       gas_tank_empty,
    output  reg                 keep_driving
);
    // Edit the code below
    always @(*) begin
        if (cpu_overheated)
            shut_off_computer = 1'b1;
        else
            shut_off_computer = 1'b0;
    end

    always @(*) begin
        if (~arrived)
            keep_driving = ~gas_tank_empty;
        else
            keep_driving = 1'b0;
    end
endmodule

module top_module (
    input       [15:0]                  scancode,
    output reg                          left,
    output reg                          down,
    output reg                          right,
    output reg                          up
); 
    always @(*) begin
        up = 1'b0; down = 1'b0; left = 1'b0; right = 1'b0;
        case (scancode)
            16'he06b: left = 1'b1;
            16'he072: down = 1'b1;
            16'he074: right = 1'b1;
            16'he075: up = 1'b1;
            defalut:;
        endcase
    end

endmodule
