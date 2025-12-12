# Personal Statement - Archit

## Overview
This repository outlines the SystemVerilog implementation and comprehensive C++ verification suite for our processor. My primary contribution to this project was the **Verification and Integration infrastructure**, ensuring functional correctness from the block level up to full system program execution.

## Summary of Contributions

As the **Verification and Integration Lead**, I was responsible for the reliability of the CPU design and ensuring it met all requirements. I built the automated testing framework, developed the testbenches with GoogleTest integration, and integrated all the required tests with the infrastructure - showing output also on Vbuddy where applicable. I adapted the test software so it correctly interfaces with our modules across different branches and implementations of the processor.

Skeleton code for parts of the software were provided verify.cpp, cpu_testbench.h, etc. and I adapted these to our implementation where required.

| Module Group | Specific Modules | Role |
| :--- | :--- | :--- |
| **Verification Infrastructure** | `doit.sh`, `verify.cpp`, `execute_pdf.cpp`, `execute_f1.cpp` | **Lead** |
| **Unit Testing** | `tb/unit_tests` | **Lead** |
| **Hardware Interface** | Vbuddy integration | **Lead** |

---

## Technical Implementation Details

### 1. Automated Regression Testing Framework (`doit.sh`)
To streamline the development cycle, I engineered a robust bash automation script that handles compilation, linking, and execution of tests.
* **Dynamic Test Selection:** Implemented a menu-driven system to run specific suites (**Unit**, **Program**, or **VBuddy**), reducing iteration time during targeted debugging.
* **Targeted Module Testing:** The script allows for further debugging by targetting any specific testbench script.
* **Output Management:** Integrated logic to capture Verilator output, using **GoogleTest** to display results in terminal, dumping waveforms to inspect using waveform viewing software, and passing output to display on Vbuddy.

### 2. GoogleTest Integration & Base Class Design
I replaced ad-hoc verification with the **GoogleTest** framework.
* **`BaseTestbench` Class:** This handles Verilator boilerplate (clock generation, trace dumping, signal initialization), streamlining the process of writing other unit tests and verification scripts, allowing them to focus purely on logic verification.

### 3. Control Unit Verification Strategy
I developed `controlunit_tb.cpp` to validate strict adherence to the RISC-V ISA.
* **Signal Mapping:** Identified and resolved discrepancies between the Decoder implementation and Datapath requirements (e.g., enforcing correct `Op1Src` vs `ALUSrc` distinctions).

### 4. Visual Hardware Verification (VBuddy)
I implemented the C++ driver logic for the `execute_f1` and `execute_pdf` tests to interface with the VBuddy peripheral.

---

## Reflection & Design Decisions

### Design Decision: Segregation of Test Suites
**Rationale:** I explicitly separated **Unit Tests** from **Program Tests**. In the project, debugging top-level failures was inefficient. By enforcing passing Unit Tests first, we ensured that individual modules were initially compliant to the RISC-V ISA and each provided the expected outputs, so top-level debugging was focused solely on integration issues, significantly speeding up the development cycle.

---

## Mistakes & Challenges


## Learnings


## Future Work
* **Code Coverage:** Integrate Verilator coverage analysis to identify untested Verilog lines.
* **Fuzz Testing:** Implement a randomized instruction generator to catch edge cases against a Golden Reference model.