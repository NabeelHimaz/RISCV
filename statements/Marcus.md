# Personal Statement - Marcus

## Summary of Contributions

As the Memory Subsystem Lead and Microarchitecture Engineer, my primary responsibility was designing and implementing the robust data and instruction memory architectures required for the RISC-V processor. I also led the development of the Pipeline Registers, the Data Cache, and advanced performance features including Dynamic Branch Prediction and the M-Extension (Hardware Multiplier).

| Module Group | Specific Modules | Role |
| :--- | :--- | :--- |
| **Data Memory** | `data_mem.sv`, `data_mem_i.sv`, `data_mem_o.sv`, `data_mem_top.sv` | **Lead** |
| **Instruction Memory** | `instrmem.sv` | **Lead** |
| **Pipeline Registers** | `pipereg_FD_1.sv`, `pipereg_DE_1.sv`, `pipereg_EM_1.sv`, `pipereg_MW_1.sv` | **Lead** |
| **Cache** | `data_cache.sv` | **Lead** |
| **Branch Prediction** | `branch_predictor.sv`, `fetch.sv` (Mod), `execute.sv` (Mod) | **Lead** |
| **M-Extension** | `ALU.sv` (Mod), `controlunit.sv` (Mod) | **Lead** |
| **Integration** | `top.sv` (Pipelined & Complete versions) | **Co-Dev** |

---

## Technical Implementation Details

### 1. Modular Data Memory Subsystem
The RISC-V ISA requires support for byte (`LB`, `SB`), half-word (`LH`, `SH`), and word (`LW`, `SW`) access. Implementing this in a single module would have resulted in complex, hard-to-debug code. I formulated a **modular design strategy**, splitting the memory into three distinct stages wrapped in `data_mem_top.sv`:

* **Input Alignment (`data_mem_i.sv`):** This module handles the `STORE` logic. It takes the 32-bit `write_data_i` and shifts it into the correct byte lanes based on the address's two least significant bits (`byte_offset`).
    * *Example:* For a Store Byte (`SB`) at address offset `01`, the data is shifted to bits `[15:8]`. This ensures that when we write to the 32-bit wide memory row, the byte lands in the correct physical location without corrupting neighbors.
* **Physical Storage (`data_mem.sv`):** I implemented the core memory as a byte-addressable array `logic [7:0] ram_array`. This was a crucial design choice over a word-addressable array, as it simplified the logic for unaligned or sub-word accesses. Writes are synchronized to the negative clock edge to ensure stability during the Execute stage.
* **Output Extension (`data_mem_o.sv`):** This module handles `LOAD` logic. It reads the raw data from memory and performs the necessary **Sign Extension** (for `LB`, `LH`) or **Zero Extension** (for `LBU`, `LHU`) based on the `MemSign` control signal.

### 2. Instruction Memory (`instrmem.sv`)
I designed the Instruction Memory as a Read-Only Memory (ROM) initialized from a hex file (`program.hex`) using `$readmemh`. I ensured the addressing logic correctly mapped the PC (Program Counter) to the physical array, supporting the processor's reset vector at `0xBFC00000` by applying a constant offset subtraction.

### 3. Pipeline Registers
To facilitate the transition to the Pipelined architecture, I implemented the pipeline registers that enforce the temporal separation of instruction stages.
* **Signal Propagation:** I carefully mapped every control signal (e.g., `RegWrite`, `MemWrite`, `ALUCtrl`) and data signal (e.g., `PC`, `ALUResult`, `Rd`) required in downstream stages.
* **Hazard Support:** I added synchronous `flush` and `stall` inputs to these registers. This allows the Hazard Unit to inject "bubbles" (NOPs) or freeze the pipeline state when data or control hazards are detected.

### 4. Two-Way Set Associative Cache
For the final "Complete" extension, I implemented a data cache to reduce memory access latency.
* **Structure:** I chose a 2-way set associative design to balance complexity and hit rate. The cache uses `Tag`, `Valid`, and `Dirty` bits for each line.
* **Stall Logic:** A critical part of this implementation was the `stall` signal generation. Upon a cache miss, I implemented logic to freeze the entire CPU pipeline while the cache controller fetches the required block from main memory.

### 5. Dynamic Branch Prediction
To overcome the significant control hazard penalties in the pipeline, I designed and integrated a **Dynamic Branch Predictor** using a Branch Target Buffer (BTB).
* **Branch Target Buffer (BTB):** Implemented a direct-mapped table with 64 entries. Each entry stores a `tag` (PC) and a `target` address.
* **2-Bit Saturating Counter:** I implemented a localized history table using a 2-bit state machine (Strongly Not Taken, Weakly Not Taken, Weakly Taken, Strongly Taken). This ensures that a single anomalous branch outcome does not immediately flip the prediction strategy.
* **Pipeline Integration:**
    * **Fetch Stage:** The predictor provides a `PredictedTargetF` immediately. If a hit occurs in the BTB and the counter indicates "Taken", the PC is updated to the target in the *same cycle*, avoiding the flush penalty entirely.
    * **Execute Stage:** I modified `execute.sv` to verify the prediction. It compares the `ActualTaken` signal (calculated by the ALU) against the `PredictTakenE` signal (passed down the pipeline). If a mismatch occurs (Misprediction), the `PCSrcE` signal triggers a pipeline flush and redirects the PC to the correct path.

## Reflection & Design Decisions

### Design Decision: Byte-Addressable vs. Word-Addressable Memory
I explicitly chose to declare the RAM array as `logic [7:0] ram_array[...]` rather than `logic`.
* **Rationale:** While a 32-bit width seems intuitive for a 32-bit CPU, it complicates byte-level writes (requiring read-modify-write cycles in hardware description). A byte-wide array allows us to write to individual indices `ram_array[addr]` without disturbing adjacent bytes, simplifying the `SB` and `SH` implementation significantly.

### Mistakes & Challenges

* **Challenge: Branch Misprediction Recovery:**
    * *Issue:* Integrating the branch predictor caused infinite loops when a misprediction occurred on a `JAL` instruction.
    * *Root Cause:* The recovery logic initially defaulted to `PC+4` for *all* mispredictions. However, if we predicted "Not Taken" for a Jump, but the Jump *was* Taken (as they always are), we need to correct to the Jump Target, not `PC+4`.
    * *Resolution:* I rewrote the `PCTargetE` logic in `execute.sv` to multiplex the recovery address based on `ActualTaken` status: if we missed a Taken branch, go to Target; if we wrongly took a Not-Taken branch, go to `PC+4`.

* **Mistake: Pipeline Synchronization of PC:**
    * *Issue:* In the early Pipelined version, `JAL` instructions were jumping to incorrect targets.
    * *Root Cause:* The `PC` value used in the Execute stage for target calculation was the *current* PC (of the instruction currently being fetched), not the PC of the instruction *in* the Execute stage.
    * *Fix:* I added `PC_F`, `PC_D`, and `PC_E` registers to the pipeline buffers, ensuring the PC value "travelled" with its instruction through the pipeline.

### Learnings
This project deepened my understanding of **hardware verification**. Debugging the memory subsystem taught me that "unit testing" is essential in hardware; attempting to debug `LB`/`SB` logic inside the full CPU was inefficient. Writing a standalone C++ testbench for `data_mem_top.sv` allowed me to verify corner cases (like writing to the last byte of a word) rapidly. I also gained significant proficiency with **SystemVerilog interfaces** and how to manage complex signal flow across multiple hierarchy levels.

---

## Future Work

If I had more time, I would:
1.  **Unified Memory:** Modify `instrmem` to be writable, creating a Von Neumann architecture. This would allow self-modifying code but would require handling structural hazards (since Fetch and Memory stages would compete for the same resource).
2.  **Advanced Cache Replacement:** Replace the current LRU-approximation policy with a Pseudo-LRU (PLRU) using tree-based bits, which scales better if we were to increase associativity to 4-way or 8-way.
3.  **Implemented Multiplier** Correctly implement a multiplier.