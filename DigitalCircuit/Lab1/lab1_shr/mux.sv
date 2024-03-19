module mux (
    input din1, din2,
    input sel,
    output reg dout
);
    always@(*) begin
        case(sel)
        1'b0: dout = din1;
        
        endcase
    end 
endmodule