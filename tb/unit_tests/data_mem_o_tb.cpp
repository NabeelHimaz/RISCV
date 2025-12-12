#include "base_testbench.h"

class DataMemOTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->read_data_i = 0;
        top->addr_i = 0;
        top->mem_type_i = 0; // default to word
        top->mem_sign_i = 0; 
    }
};

//basic load word test (lw)
//if mem_type is 00 (default), it should just pass the raw data through
//regardless of the address or sign bit
TEST_F(DataMemOTestbench, LoadWord_Passthrough)
{
    top->read_data_i = 0xDEADBEEF;
    top->mem_type_i = 0; // word
    top->addr_i = 0x100; // address shouldn't matter for word alignment here (assumed aligned)
    
    tick();

    EXPECT_EQ(top->read_data_o, 0xDEADBEEF);
}

//load byte unsigned (lbu)
//logic: mem_type 01, mem_sign 1
//we feed in a word like 0x44332211 and make sure we can pick out each byte
//and that it's zero-extended
TEST_F(DataMemOTestbench, LBU_ByteSelection)
{
    top->read_data_i = 0x44332211;
    top->mem_type_i = 1; // byte
    top->mem_sign_i = 1; // unsigned

    //check byte 0 (0x11)
    top->addr_i = 0x00; 
    tick();
    EXPECT_EQ(top->read_data_o, 0x00000011);

    //check byte 1 (0x22)
    top->addr_i = 0x01; 
    tick();
    EXPECT_EQ(top->read_data_o, 0x00000022);

    //check byte 2 (0x33)
    top->addr_i = 0x02; 
    tick();
    EXPECT_EQ(top->read_data_o, 0x00000033);

    //check byte 3 (0x44)
    top->addr_i = 0x03; 
    tick();
    EXPECT_EQ(top->read_data_o, 0x00000044);
}

//load byte signed (lb)
//logic: mem_type 01, mem_sign 0
//checking if a negative byte (bit 7 is 1) gets sign extended correctly
TEST_F(DataMemOTestbench, LB_SignExtension)
{
    //0x80 is negative in 8-bit logic (1000 0000)
    //so we want input bytes that will trigger extension
    top->read_data_i = 0x80808080; 
    top->mem_type_i = 1; // byte
    top->mem_sign_i = 0; // signed

    //check byte 0
    top->addr_i = 0x00;
    tick();
    //expecting 0xFFFFFF80
    EXPECT_EQ(top->read_data_o, 0xFFFFFF80);

    //check byte 3 (just to be sure logic holds for upper bytes)
    top->addr_i = 0x03;
    tick();
    EXPECT_EQ(top->read_data_o, 0xFFFFFF80);
}

//load half unsigned (lhu)
//logic: mem_type 10, mem_sign 1
//checks selection of bottom half vs top half
TEST_F(DataMemOTestbench, LHU_HalfSelection)
{
    //input: 0xBBBBAAAA
    top->read_data_i = 0xBBBBAAAA;
    top->mem_type_i = 2; // half (binary 10)
    top->mem_sign_i = 1; // unsigned

    //check lower half (addr ends in 00 or 01, usually 00 for aligned)
    top->addr_i = 0x00;
    tick();
    //expecting 0x0000AAAA
    EXPECT_EQ(top->read_data_o, 0x0000AAAA);

    //check upper half (addr ends in 10)
    top->addr_i = 0x02;
    tick();
    //expecting 0x0000BBBB
    EXPECT_EQ(top->read_data_o, 0x0000BBBB);
}

//load half signed (lh)
//logic: mem_type 10, mem_sign 0
//checks if negative 16-bit value gets sign extended
TEST_F(DataMemOTestbench, LH_SignExtension)
{
    //0xF00D is negative in 16-bit (starts with 1)
    //0x700D is positive (starts with 0)
    //let's put negative in lower, positive in upper
    top->read_data_i = 0x700DF00D;
    top->mem_type_i = 2; // half
    top->mem_sign_i = 0; // signed

    //check lower half (negative)
    top->addr_i = 0x00;
    tick();
    //should extend the Fs
    EXPECT_EQ(top->read_data_o, 0xFFFFF00D);

    //check upper half (positive)
    top->addr_i = 0x02;
    tick();
    //should NOT extend Fs, just 0s
    EXPECT_EQ(top->read_data_o, 0x0000700D);
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}