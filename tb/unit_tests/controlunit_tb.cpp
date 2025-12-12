#include "base_testbench.h"

class ControlUnitTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->Instr_i = 0;
        top->branchTaken_i = 0; // Changed from Zero_i
    }
};

//NH: to fix
//verify that ADDI performs an ADD (0000) even if bit 30 (funct7) is set.
TEST_F(ControlUnitTestbench, ADDI_Negative_Immediate)
{
    //0x40000013 -> Bit 30 is High, Op is 19 (ADDI)
    top->Instr_i = 0x40000013; 
    top->branchTaken_i = 0; // Changed from Zero_i

    tick();

    //expect ALUCtrl to be ADD (0), NOT SUB (1)
    EXPECT_EQ(top->ALUCtrl_o, 0b0000);

    //basic I-Type checks
    EXPECT_EQ(top->RegWrite_o, 1);
    EXPECT_EQ(top->ALUSrcB_o, 1); // Changed from ALUSrc_o
}

//NH & AT: to fix
//verify that Branches compare Register vs Register (ALUSrc = 0).
TEST_F(ControlUnitTestbench, Branch_ALUSrc)
{
    top->Instr_i = 0x00000063; // BEQ
    top->branchTaken_i = 0; // Changed from Zero_i

    tick();

    // Expect ALUSrc to be 0 (Register B), NOT 1 (Immediate)
    EXPECT_EQ(top->ALUSrcB_o, 0); // Changed from ALUSrc_o
}

// ============================================================
// R-TYPE INSTRUCTION TESTS (Opcode 51 / 0x33)
// ============================================================

// Test R-Type ADD (funct3 = 000, funct7 = 00)
TEST_F(ControlUnitTestbench, R_Type_ADD)
{
    // Op: 51, rd:1, rs1:1, rs2:1, f3:0, f7:0
    top->Instr_i = 0x001080B3; 
    tick();

    EXPECT_EQ(top->RegWrite_o, 1);
    EXPECT_EQ(top->ALUSrcB_o, 0);    // Changed from ALUSrc_o
    EXPECT_EQ(top->ALUCtrl_o, 0);   // ADD
    EXPECT_EQ(top->MemWrite_o, 0);
    EXPECT_EQ(top->ResultSrc_o, 0); // ALU Result
}

// Test R-Type SUB (funct3 = 000, funct7 = 0x20 -> Bit 30 is 1)
TEST_F(ControlUnitTestbench, R_Type_SUB)
{
    // Op: 51, f3: 0, Bit 30: 1 -> 0x40000033
    top->Instr_i = 0x40000033; 
    tick();

    EXPECT_EQ(top->RegWrite_o, 1);
    EXPECT_EQ(top->ALUCtrl_o, 1);   // SUB
}

// Test R-Type AND (funct3 = 111)
TEST_F(ControlUnitTestbench, R_Type_AND)
{
    // Op: 51, f3: 7 -> 0x00007033
    top->Instr_i = 0x00007033; 
    tick();

    EXPECT_EQ(top->ALUCtrl_o, 2);   // AND (0010)
}

// ============================================================
// I-TYPE ARITHMETIC TESTS (Opcode 19 / 0x13)
// ============================================================

// Test SLTI (Set Less Than Immediate)
TEST_F(ControlUnitTestbench, I_Type_SLTI)
{
    // Op: 19, f3: 2 (SLT) -> 0x00002013
    top->Instr_i = 0x00002013;
    tick();

    EXPECT_EQ(top->ALUCtrl_o, 5);   // SLT (0101)
    EXPECT_EQ(top->ALUSrcB_o, 1);    // Changed from ALUSrc_o
    EXPECT_EQ(top->ImmSrc_o, 0);    // I-Type Immediate
}

// ============================================================
// MEMORY ACCESS TESTS (Load: 3, Store: 35)
// ============================================================

// Test LW (Load Word)
TEST_F(ControlUnitTestbench, Instruction_LW)
{
    top->Instr_i = 0x00002003; // LW (Op 3)
    tick();

    EXPECT_EQ(top->RegWrite_o, 1);
    EXPECT_EQ(top->ALUSrcB_o, 1);    // Changed from ALUSrc_o
    EXPECT_EQ(top->ALUCtrl_o, 0);   // ADD address calculation
    EXPECT_EQ(top->MemWrite_o, 0);
    EXPECT_EQ(top->ResultSrc_o, 1); // ReadData from Memory
    EXPECT_EQ(top->ImmSrc_o, 0);    // I-Type Immediate
}

// Test SW (Store Word)
TEST_F(ControlUnitTestbench, Instruction_SW)
{
    top->Instr_i = 0x00002023; // SW (Op 35)
    tick();

    EXPECT_EQ(top->RegWrite_o, 0);  // Don't write to reg file
    EXPECT_EQ(top->MemWrite_o, 1);  // Write to memory
    EXPECT_EQ(top->ALUSrcB_o, 1);    // Changed from ALUSrc_o
    EXPECT_EQ(top->ALUCtrl_o, 0);   // ADD address calculation
    EXPECT_EQ(top->ImmSrc_o, 1);    // S-Type Immediate (3'b001)
}

// ============================================================
// BRANCHING LOGIC TESTS (Opcode 99 / 0x63)
// ============================================================

// Test BEQ when Not Taken (Zero_i = 0)
TEST_F(ControlUnitTestbench, BEQ_NotTaken)
{
    top->Instr_i = 0x00000063; // BEQ
    top->branchTaken_i = 0;          // Changed from Zero_i
    tick();

    EXPECT_EQ(top->PCSrc_o, 0);     // PC = PC + 4
    EXPECT_EQ(top->RegWrite_o, 0);
    EXPECT_EQ(top->ImmSrc_o, 2);    // B-Type Immediate (3'b010)
}

// Test BEQ when Taken (Zero_i = 1)
TEST_F(ControlUnitTestbench, BEQ_Taken)
{
    top->Instr_i = 0x00000063; // BEQ
    top->branchTaken_i = 1;          // Changed from Zero_i
    tick();

    EXPECT_EQ(top->PCSrc_o, 1);     // PC = PC + Imm
    EXPECT_EQ(top->RegWrite_o, 0);
}

// ============================================================
// JUMP TESTS (JAL: 111, JALR: 103)
// ============================================================

// Test JAL (Jump And Link)
TEST_F(ControlUnitTestbench, Instruction_JAL)
{
    top->Instr_i = 0x0000006F; // JAL (Op 111)
    tick();

    EXPECT_EQ(top->PCSrc_o, 1);     // Always Jump
    EXPECT_EQ(top->RegWrite_o, 1);  // Save PC+4
    EXPECT_EQ(top->ResultSrc_o, 2); // Source is PC+4 (2'b10)
    EXPECT_EQ(top->ImmSrc_o, 4);    // J-Type Imm (3'b100)
}

// Test JALR (Jump And Link Register)
TEST_F(ControlUnitTestbench, Instruction_JALR)
{
    top->Instr_i = 0x00000067; // JALR (Op 103)
    tick();

    EXPECT_EQ(top->PCSrc_o, 1);     // Jump
    EXPECT_EQ(top->RegWrite_o, 1);  // Save PC+4
    EXPECT_EQ(top->ResultSrc_o, 2); // Source is PC+4
    EXPECT_EQ(top->ALUSrcB_o, 1);    // Changed from ALUSrc_o
    EXPECT_EQ(top->ImmSrc_o, 0);    // I-Type Imm
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}