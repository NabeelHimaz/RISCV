module extend #(
    parameter DATA_WIDTH = 32
) (
    input  logic [DATA_WIDTH-1:0]   instr_i,
    input  logic [2:0]              ImmSrc_i,


    output logic [DATA_WIDTH-1:0]   immop_o  
);

    always_comb begin
        case(ImmSrc_i)
            3'b000: immop_o = {{20{instr_i[31]}}, intr_i[31:20]}; //type I 

            3'b001: immop_o = {{20{intr_i[31]}}, intr_i[31:25], intr_i[11:7]}; //type S
            
            3'b010: immop_o = {{20{intr_i[31]}}, intr_i[7], intr_i[30:25], intr_i[11:8], 1'b0}; //type B 
            
            3'b011: immop_o = {{12{intr[31]}}, intr_i[19:12], intr_i[20] , intr_i[30:21]};  //type J

            3'b100: immop_o = {instr_i[31:12], 12'b0};  //type U
            
            default: 
                immop_o = {{DATA_WIDTH}{1'b0}};
            
        endcase //closed the case
    end //closed the begin

endmodule