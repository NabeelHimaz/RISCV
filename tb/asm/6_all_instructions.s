# Comprehensive RISC-V 32I Instruction Test
# -----------------------------------------------------
# Validates ALU ops, Memory ops, and Immediate handling.

    # ---------------------------------------------------
    # 1. IMMEDIATE & ARITHMETIC (I-Type & R-Type)
    # ---------------------------------------------------
    # x1 = 10, x2 = 20, x3 = -15
    addi x1, x0, 10
    addi x2, x0, 20
    addi x3, x0, -15
    
    add  x4, x1, x2      # x4 = 30  (ADD)
    sub  x5, x2, x1      # x5 = 10  (SUB)
    
    # Logical
    and  x6, x1, x2      # x6 = 0   (10 & 20 = 0)
    or   x7, x1, x2      # x7 = 30  (10 | 20 = 30)
    xor  x8, x1, x2      # x8 = 30  (10 ^ 20 = 30)
    
    # Shifts
    addi x9, x0, 1       # x9 = 1
    sll  x10, x9, x1     # x10 = 1 << 10 = 1024
    srl  x11, x10, x1    # x11 = 1024 >> 10 = 1
    sra  x12, x3, x9     # x12 = -15 >>> 1 = -8 (Arithmetic shift preserves sign)

    # Comparisons (SLT/SLTU)
    slt  x13, x3, x1     # x13 = 1  (-15 < 10 is True)
    sltu x14, x3, x1     # x14 = 0  (Large unsigned > 10 is False)

    # ---------------------------------------------------
    # 2. UPPER IMMEDIATES (U-Type)
    # ---------------------------------------------------
    lui  x15, 0x1        # x15 = 0x1000 (Load Upper Immediate)
    auipc x16, 0         # x16 = PC of this instruction

    # ---------------------------------------------------
    # 3. MEMORY OPERATIONS (S-Type & L-Type)
    # ---------------------------------------------------
    # Base address for memory = 0x100
    addi x20, x0, 0x100
    
    # Store Word, Half, Byte
    sw   x15, 0(x20)     # Store 0x00001000 at Mem[0x100]
    addi x21, x0, 0x55
    sb   x21, 4(x20)     # Store 0x55 at Mem[0x104] (Byte)
    
    # Load Word, Half, Byte
    lw   x22, 0(x20)     # x22 = 0x00001000
    lbu  x23, 4(x20)     # x23 = 0x00000055 (Unsigned byte)
    
    # Load-Use Hazard check (Implicitly testing your Stall unit)
    lw   x24, 0(x20)     # Load 0x1000
    add  x25, x24, x24   # x25 = 0x2000 (Should stall 1 cycle to get x24)

    # ---------------------------------------------------
    # 4. BRANCHING LOGIC (B-Type)
    # ---------------------------------------------------
    addi x26, x0, 10
    addi x27, x0, 10
    
    # BEQ TEST
    beq  x26, x27, branch_target
    addi x28, x0, 0xB    # 0xB = "Bad" marker (Should skip this)
    
branch_target:
    addi x28, x0, 0xD    # 0xD = "Done/Good" marker
    
    # BLT TEST
    blt  x3, x1, jump_end # -15 < 10, should take branch
    addi x29, x0, 0xB    # 0xB = "Bad" marker

jump_end:
    jal  x0, program_end

    # ---------------------------------------------------
    # END
    # ---------------------------------------------------
program_end:
    beq x0, x0, program_end
