# RISC-V Assembly Testbench for Hazard Validation
# -----------------------------------------------
# 1. MEM -> EX Forwarding
# 2. WB -> EX Forwarding
# 3. Load-Use Stall

    # ---------------------------------------------------
    # INITIAL SETUP
    # ---------------------------------------------------
    addi x1, x0, 10      # x1 = 10
    addi x2, x0, 20      # x2 = 20
    addi x10, x0, 100    # x10 = 100 (Base address for memory tests)

    # ---------------------------------------------------
    # TEST 1: MEM -> EX Forwarding (Distance 1)
    # ---------------------------------------------------
    # The ADD produces 30. It is in the MEM stage when SUB needs it in EX.
    # Logic: ForwardAE = 2'b10 (from Memory)
    
    add  x3, x1, x2      # x3 = 10 + 20 = 30  (Producer)
    sub  x4, x3, x1      # x4 = 30 - 10 = 20  (Consumer - Needs x3 NOW)

    # ---------------------------------------------------
    # TEST 2: WB -> EX Forwarding (Distance 2)
    # ---------------------------------------------------
    # The AND produces 0. We insert a buffer op. 
    # The AND is in WB stage when OR needs it in EX.
    # Logic: ForwardAE = 2'b01 (from Writeback)
    
    and  x5, x1, x2      # x5 = 10 & 20 = 0   (Producer)
    addi x0, x0, 0       # NOP                (Buffer)
    or   x6, x5, x2      # x6 = 0 | 20 = 20   (Consumer - Needs x5 from WB)

    # ---------------------------------------------------
    # TEST 3: Load-Use Hazard (Stall Requirement)
    # ---------------------------------------------------
    # We load 55 from memory. The very next instruction tries to use it.
    # Forwarding is impossible. The Hazard Unit MUST insert a stall.
    # Logic: StallF=1, StallD=1, FlushE=1
    
    addi x11, x0, 55     # x11 = 55
    sw   x11, 0(x10)     # Store 55 at Mem[100]
    lw   x7, 0(x10)      # Load 55 into x7    (Producer - Load)
    add  x8, x7, x1      # x8 = 55 + 10 = 65  (Consumer - Use Hazard!)

    # ---------------------------------------------------
    # END LOOP
    # ---------------------------------------------------
finish:
    beq  x0, x0, finish
