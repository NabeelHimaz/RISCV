module controlunit #(
    parameter DATA_WIDTH = 32
) (
    input  logic [DATA_WIDTH-1:0]   Instr_i,
    input  logic                    Zero_i,         //only needed for beq instructions

    output logic                    RegWrite_o,
    output logic [3:0]              ALUCtrl_o,      //determined using func3 and the 5th bits of op and funct7
    output logic                    ALUSrc_o,
    //output logic [1:0]              ALUSrcA_o,
    //output logic [1:0]              ALUSrcB_o,
    output logic [1:0]              ImmSrc_o,       //decides which instruction bits to use as the immediate
    output logic                    PCSrc_o,
    output logic                    MemWrite_o,    
    output logic [1:0]              ResultSrc_o
    //output logic                    JumpD_o
    //output logic                    BranchD
    //output logic                    PCWrite_o,
    //output logic                    AdrSrc_o,
    //output logic                    IRWrite_o,
);

    logic [6:0]     op;
    logic           funct7_5;
    logic [2:0]     funct3;

    assign op =     Instr[6:0];
    assign funct3 =  Instr[14:12];
    assign funct7_5 = Instr[30];

    always_comb begin 
        case(op)
            7'd3: begin                                                     //I-type 
                ALUCtrl_o = 4'b0;
                case(funct3) 
                    3'b000, 3'b001, 3'b010: begin
                        ImmSrc_o = 2'b00;                                   //sign extend Instr[31:20] 
                    end
                    3'b100, 3'b101: begin
                        ImmSrc_o = 2'b;                                     //zero extend Instr[31:20]
                    end
            end

            7'd19, 7'd51: begin                                             //Arithmetic I-type and R-type
                ImmSrc_o = 2'b10;                                           //not sure if correct, should be sign extended

                case(func3)
                    3'b000: ALUCtrl_o = (funct7_5) ? 4'b0001 : 4'b0000;     //sub, add           
                    3'b001: ALUCtrl_o = 4'b1000;                            //logical shift left                      
                    3'b010: ALUCtrl_o = 4'b0101;                            //set less than signed                  
                    3'b011: ALUCtrl_o = 4'b0110;                            //set less than unsigned   
                    3'b100: ALUCtrl_o = 4'b0011;                            //xor
                    3'b101: ALUCtrl_o = (funct7_5) ? 4'b1001 : 4'b0111;     //arithmetic shift right, logical shift right
                    3'b110: ALUCtrl_o = 4'b0011;                            //or
                    3'b111: ALUCtrl_o = 4'b0010;                            //and
                        
                  

            end

            //7'd23, 7'd55: begin //U-type
            //    ImmSrc_o    =
            //    ALUCtrl_o   =
            //end

            7'd35: begin                //S-type
                ImmSrc_o    = 2'b01;
                ALUCtrl_o   = 4'b0000;
            end

            7'd99: begin                //B-type
                ImmSrc_o    = 2'b10;
                ALUCtrl_o   = 4'b0000;  //doesnt matter
            end

            7'd103: begin
                ImmSrc_o = 2'b00;
                ALUCtrl_o = 4'b1011;    //need a new ALU instruction
            end
            7'd111: begin
                ImmSrc_o = 
                ALUCtrl_o = 4'b0000;    //need new ALU instruct
            end

    end

    always_comb begin
        MemWrite_o      = (op == 7'd35) ? 1'b1 : 1'b0;
        RegWrite_o      = (op == 7'd35 || 7'd99 || 7'd103 || 7'd111) ? 1'b0 : 1'b1;
        ALUSrc_o        = (op == 7'd51) ? 1'b0 : 1'b1;
        ResultSrc_o     = (op == 7'd3) ? 1'b1 : 1'b0;
        PCSrc_o         = (op == 7'd103 || 7'd111) ? 1'b0 : 1'b1;
    end

endmodule
