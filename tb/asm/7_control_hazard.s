# Control Hazard & Flush Verification
# -----------------------------------------------
# Goal: Ensure instructions fetched speculatively during a branch/jump
# are FLUSHED and do not modify the register file.

    # ---------------------------------------------------
    # SETUP
    # ---------------------------------------------------
    addi x1, x0, 5      # x1 = 5
    addi x2, x0, 5      # x2 = 5
    addi x3, x0, 10     # x3 = 10
    
    # ---------------------------------------------------
    # TEST 1: BEQ (Taken) - The Flush Test
    # ---------------------------------------------------
    # If x1 == x2 (True), we branch to 'safe_zone_1'.
    # The instruction immediately following MUST be flushed.
    
    beq  x1, x2, safe_zone_1
    addi x10, x0, 0x1        # POISON! Should be flushed.
    addi x11, x0, 0x1        # POISON! Should be flushed.

safe_zone_1:
    addi x4, x0, 0x1         # x4 = 1 (Marker: Test 1 Passed if reached)

    # ---------------------------------------------------
    # TEST 2: BNE (Not Taken) - The Fallthrough Test
    # ---------------------------------------------------
    # BNE x1, x2 (5 != 5 is False). Branch NOT taken.
    
    bne  x1, x2, bad_zone_2  # Should NOT branch
    addi x5, x0, 0x2         # x5 = 2 (Marker: Test 2 Correctly fell through)
    jal  x0, skip_bad_2      # Jump over the bad zone

bad_zone_2:
    addi x12, x0, 0x1        # POISON! Should not be executed.

skip_bad_2:
    # ---------------------------------------------------
    # TEST 3: JAL (Unconditional Jump) - The Flush Test
    # ---------------------------------------------------
    # Jumps are resolved in Execute. Prefetched instructions must die.
    
    jal  x6, safe_zone_3     # x6 = Return Address
    addi x13, x0, 0x1        # POISON! Should be flushed.

safe_zone_3:
    addi x7, x0, 0x3         # x7 = 3 (Marker: Test 3 Passed)

    # ---------------------------------------------------
    # TEST 4: JALR (Jump Register)
    # ---------------------------------------------------
    la   x8, finish          # Load address of 'finish' into x8
    jalr x9, 0(x8)           # Jump to address in x8. x9 = Return Address.
    addi x14, x0, 0x1        # POISON! Should be flushed.

finish:
    addi x15, x0, 0xF        # x15 = 15 (Success Marker)
    beq  x0, x0, finish      # Infinite Loop
