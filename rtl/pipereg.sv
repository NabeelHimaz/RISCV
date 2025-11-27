module pipereg #(
    parameter WIDTH = 32
)(
    input  logic             clk,
    input  logic             rst,
    input  logic             en,    // Enable (usually 1'b1 unless stalling)
    input  logic             clr,   // Flush (synchronous reset for hazards)
    input  logic [WIDTH-1:0] d,
    output logic [WIDTH-1:0] q
);

    always_ff @(posedge clk) begin
        if (rst)         q <= {WIDTH{1'b0}};
        else if (clr)    q <= {WIDTH{1'b0}};
        else if (en)     q <= d;
    end

endmodule