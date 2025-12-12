#include "base_testbench.h"

class ControlUnitTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->Instr_i = 0;
    }
};

//verify addi works with negative immediates
//funct3 is 000. bit 30 is set (like in sub) but it should still be an add
TEST_F(ControlUnitTestbench, ADDI_Negative_Immediate)
{
    //addi x1, x2, -1 (0xFFF10093). bit 30 is high
    top->Instr_i = 0xFFF10093; 
    
    tick();

    //alu control should be 0 (add), not 1 (sub)
    EXPECT_EQ(top->ALUCtrl_o, 0b0000);

    //check other signals
    EXPECT_EQ(top->RegWrite_o, 1);
    EXPECT_EQ(top->ALUSrc_o, 1);    // Updated from ALUSrcB_o
    EXPECT_EQ(top->Op1Src_o, 0);    // Updated from ALUSrcA_o (0=Reg)
    EXPECT_EQ(top->ResultSrc_o, 0); 
    EXPECT_EQ(top->ImmSrc_o, 0);    
}

//basic r-type add (funct3 = 000, funct7 = 0000000)
TEST_F(ControlUnitTestbench, R_Type_ADD)
{
    //add x1, x2, x3
    top->Instr_i = 0x003100B3; 
    tick();

    EXPECT_EQ(top->RegWrite_o, 1);
    EXPECT_EQ(top->ALUSrc_o, 0);    // Updated from ALUSrcB_o
    EXPECT_EQ(top->ALUCtrl_o, 0);   // add
}

//r-type sub (funct3 = 000), checks if bit 30 triggers subtraction
TEST_F(ControlUnitTestbench, R_Type_SUB)
{
    //sub x1, x2, x3. bit 30 is high (funct7 = 0100000)
    top->Instr_i = 0x403100B3; 
    tick();

    EXPECT_EQ(top->RegWrite_o, 1);
    EXPECT_EQ(top->ALUSrc_o, 0);   
    EXPECT_EQ(top->ALUCtrl_o, 1);   //sub
}

//ensure branches (opcode 99) compare reg vs reg, not reg vs imm
TEST_F(ControlUnitTestbench, Branch_ALUSrc_Check)
{
    top->Instr_i = 0x00000063; //beq (funct3 = 000)
    tick();

    //alusrcb should be 0 for branches
    EXPECT_EQ(top->ALUSrc_o, 0); 
}

//check BEQ decode logic (PCSrc calculation moved to Execute stage in new design)
TEST_F(ControlUnitTestbench, Instruction_BEQ)
{
    top->Instr_i = 0x00000063; //beq (funct3 = 000)
    
    tick();
    
    // Just verify it decodes as a branch
    EXPECT_EQ(top->BranchInstr_o, 1); 
    EXPECT_EQ(top->Branch_o, 0b000);   // BEQ
    EXPECT_EQ(top->RegWrite_o, 0); 
    EXPECT_EQ(top->ImmSrc_o, 2);       // b-type
}

//check if branch_o outputs correct encoding from funct3
TEST_F(ControlUnitTestbench, Branch_Output_Encoding)
{
    //bne (funct3 = 001)
    top->Instr_i = 0x00001063;
    tick();
    EXPECT_EQ(top->Branch_o, 0b001); 

    //blt (funct3 = 100)
    top->Instr_i = 0x00004063;
    tick();
    EXPECT_EQ(top->Branch_o, 0b100); 
}

//load word test (opcode 3, funct3 = 010)
TEST_F(ControlUnitTestbench, Instruction_LW)
{
    //lw x1, 0(x2)
    top->Instr_i = 0x00002003; 

    tick();

    EXPECT_EQ(top->RegWrite_o, 1);
    EXPECT_EQ(top->ALUCtrl_o, 0);   //add for address calc
    EXPECT_EQ(top->MemWrite_o, 0);
    EXPECT_EQ(top->ResultSrc_o, 1); //from memory
    EXPECT_EQ(top->ImmSrc_o, 0);    //i-type
    
    EXPECT_EQ(top->Op1Src_o, 0);    // Updated from ALUSrcA_o (reg)
    EXPECT_EQ(top->ALUSrc_o, 1);    // Updated from ALUSrcB_o (imm)
    EXPECT_EQ(top->MemType_o, 0);   //word width (for funct3 = 010)
}

//load byte unsigned (opcode 3, funct3 = 100), checking memsign
TEST_F(ControlUnitTestbench, Instruction_LBU)
{
    //lbu x1, 0(x2)
    top->Instr_i = 0x00014083;
    tick();

    EXPECT_EQ(top->RegWrite_o, 1);
    //funct3 100 means memtype 01 and signed 1
    EXPECT_EQ(top->MemType_o, 1);
    EXPECT_EQ(top->MemSign_o, 1); 
}

//store word test (opcode 35, funct3 = 010)
TEST_F(ControlUnitTestbench, Instruction_SW)
{
    //sw x1, 0(x2)
    top->Instr_i = 0x00112023; 
    tick();

    EXPECT_EQ(top->RegWrite_o, 0); 
    EXPECT_EQ(top->MemWrite_o, 1); 
    EXPECT_EQ(top->ALUSrc_o, 1);    
    EXPECT_EQ(top->ImmSrc_o, 1);    //s-type
}

//jal test (opcode 111)
TEST_F(ControlUnitTestbench, Instruction_JAL)
{
    top->Instr_i = 0x0000006F; 
    tick();

    // Updated: PCSrc logic is external now, checking other signals
    EXPECT_EQ(top->ResultSrc_o, 2); 
    EXPECT_EQ(top->RegWrite_o, 1);  //save pc+4
    EXPECT_EQ(top->ImmSrc_o, 4);    //j-type
    EXPECT_EQ(top->JumpSrc_o, 0);   //0 for jal
    EXPECT_EQ(top->Op1Src_o, 1);    // PC
}

//jalr test (opcode 103, funct3 = 000)
TEST_F(ControlUnitTestbench, Instruction_JALR)
{
    top->Instr_i = 0x00010067; 
    tick();

    EXPECT_EQ(top->RegWrite_o, 1);  
    EXPECT_EQ(top->ResultSrc_o, 2); 
    EXPECT_EQ(top->ALUSrc_o, 1);   
    EXPECT_EQ(top->ImmSrc_o, 0);    //i-type
    EXPECT_EQ(top->JumpSrc_o, 1);   //1 for jalr
}

//lui test (opcode 55)
TEST_F(ControlUnitTestbench, Instruction_LUI)
{
    top->Instr_i = 0x000000B7;
    tick();

    EXPECT_EQ(top->RegWrite_o, 1);
    EXPECT_EQ(top->ImmSrc_o, 3);    //u-type
    EXPECT_EQ(top->ALUSrc_o, 1);
    EXPECT_EQ(top->Op1Src_o, 2);
}

//auipc test (opcode 23)
TEST_F(ControlUnitTestbench, Instruction_AUIPC)
{
    top->Instr_i = 0x00000017;
    tick();

    EXPECT_EQ(top->RegWrite_o, 1);
    EXPECT_EQ(top->ImmSrc_o, 3);    
    EXPECT_EQ(top->Op1Src_o, 1);
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}