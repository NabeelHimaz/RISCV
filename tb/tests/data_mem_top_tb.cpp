#include "base_testbench.h"

class DataMemTopTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk_i = 0;
        top->write_en_i = 0;
        top->addr_i = 0;
        top->write_data_i = 0;
        top->mem_type_i = 0; // default to word
        top->mem_sign_i = 0; // default to signed
    }

    void stepClock()
    {
        // rising edge
        top->clk_i = 1;
        tick(); 
        
        // falling edge - this is usually when the write happens in memory
        top->clk_i = 0;
        tick(); 
    }
};

//basic word read/write test
//write a full 32-bit value and make sure we get it back
TEST_F(DataMemTopTestbench, WordReadWrite)
{
    //write 0xdeadbeef to address 0x100
    top->write_en_i = 1;
    top->mem_type_i = 0; // word
    top->addr_i = 0x100;
    top->write_data_i = 0xDEADBEEF;
    stepClock();

    //turn off write and read it back
    top->write_en_i = 0;
    tick(); 

    EXPECT_EQ(top->read_data_o, 0xDEADBEEF);
}

//byte access test with offsets
//we write 4 individual bytes to fill up a word, then read them back
//this tests if your data_mem_i correctly shifts inputs based on address bits [1:0]
TEST_F(DataMemTopTestbench, StoreLoadByte_Offsets)
{
    uint32_t base_addr = 0x200;

    top->write_en_i = 1;
    top->mem_type_i = 1; // byte
    
    //write 0x11 at offset 0
    top->addr_i = base_addr + 0;
    top->write_data_i = 0x11; 
    stepClock();

    //write 0x22 at offset 1
    top->addr_i = base_addr + 1;
    top->write_data_i = 0x22; 
    stepClock();

    //write 0x33 at offset 2
    top->addr_i = base_addr + 2;
    top->write_data_i = 0x33; 
    stepClock();

    //write 0x44 at offset 3
    top->addr_i = base_addr + 3;
    top->write_data_i = 0x44; 
    stepClock();

    //read phase
    top->write_en_i = 0;
    top->mem_sign_i = 1; // unsigned read (lbu) just to see the raw byte

    //check offset 0
    top->addr_i = base_addr + 0;
    tick();
    EXPECT_EQ(top->read_data_o, 0x11);

    //check offset 1
    top->addr_i = base_addr + 1;
    tick();
    EXPECT_EQ(top->read_data_o, 0x22);

    //check offset 2
    top->addr_i = base_addr + 2;
    tick();
    EXPECT_EQ(top->read_data_o, 0x33);

    //check offset 3
    top->addr_i = base_addr + 3;
    tick();
    EXPECT_EQ(top->read_data_o, 0x44);

    //verify the full word looks like 0x44332211 (little endian)
    top->mem_type_i = 0; // word
    top->addr_i = base_addr;
    tick();
    EXPECT_EQ(top->read_data_o, 0x44332211); 
}

//check if sign extension works for bytes
//store 0xff (which is -1 in 8-bit signed)
TEST_F(DataMemTopTestbench, LoadByte_SignExtension)
{
    top->write_en_i = 1;
    top->mem_type_i = 1; // byte
    top->addr_i = 0x300;
    top->write_data_i = 0xFF; 
    stepClock();

    top->write_en_i = 0;

    //1. test signed load (lb). mem_sign_i = 0
    //should extend to 0xffffffff
    top->mem_sign_i = 0; 
    tick();
    EXPECT_EQ(top->read_data_o, 0xFFFFFFFF);

    //2. test unsigned load (lbu). mem_sign_i = 1
    //should be just 0x000000ff
    top->mem_sign_i = 1; 
    tick();
    EXPECT_EQ(top->read_data_o, 0x000000FF);
}

//half-word access test
//similar to byte test, but writing 16 bits at a time
TEST_F(DataMemTopTestbench, StoreLoadHalf_Offsets)
{
    uint32_t base_addr = 0x400;

    top->write_en_i = 1;
    top->mem_type_i = 2; // half
    
    //write 0xaaaa at offset 0 (bytes 0,1)
    top->addr_i = base_addr;
    top->write_data_i = 0xAAAA;
    stepClock();

    //write 0xbbbb at offset 2 (bytes 2,3)
    top->addr_i = base_addr + 2;
    top->write_data_i = 0xBBBB;
    stepClock();

    //read phase
    top->write_en_i = 0;
    top->mem_sign_i = 1; // unsigned (lhu)

    //check lower half
    top->addr_i = base_addr;
    tick();
    EXPECT_EQ(top->read_data_o, 0xAAAA);

    //check upper half
    top->addr_i = base_addr + 2;
    tick();
    EXPECT_EQ(top->read_data_o, 0xBBBB);

    //verify full word is bbbbaaaa
    top->mem_type_i = 0;
    top->addr_i = base_addr;
    tick();
    EXPECT_EQ(top->read_data_o, 0xBBBBAAAA); 
}

//half-word sign extension test
//store 0xf00d (negative in 16-bit)
TEST_F(DataMemTopTestbench, LoadHalf_SignExtension)
{
    top->write_en_i = 1;
    top->mem_type_i = 2; // half
    top->addr_i = 0x500;
    top->write_data_i = 0xF00D;
    stepClock();

    top->write_en_i = 0;

    //1. test signed load (lh). should be 0xfffff00d
    top->mem_sign_i = 0;
    tick();
    EXPECT_EQ(top->read_data_o, 0xFFFFF00D);

    //2. test unsigned load (lhu). should be 0x0000f00d
    top->mem_sign_i = 1;
    tick();
    EXPECT_EQ(top->read_data_o, 0x0000F00D);
}

//integrity check
//making sure writing a single byte doesn't wipe out the rest of the word
TEST_F(DataMemTopTestbench, ReadModifyWrite_Integrity)
{
    uint32_t addr = 0x600;

    //1. fill word with all Fs
    top->write_en_i = 1;
    top->mem_type_i = 0; // word
    top->addr_i = addr;
    top->write_data_i = 0xFFFFFFFF;
    stepClock();

    //2. overwrite just byte 1 (offset 1) with 0x00
    top->mem_type_i = 1; // byte
    top->addr_i = addr + 1;
    top->write_data_i = 0x00;
    stepClock();

    //3. read back. expected: 0xff00ffff
    top->write_en_i = 0;
    top->mem_type_i = 0; // word
    top->addr_i = addr;
    tick();

    EXPECT_EQ(top->read_data_o, 0xFFFF00FF);
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}