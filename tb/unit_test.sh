#!/bin/bash

# This script runs all unit tests (*_tb.cpp) in the tests/ directory.
# Usage: ./run_unit_tests.sh

# Constants
SCRIPT_DIR=$(dirname "$(realpath "$0")")
TEST_FOLDER=$(realpath "$SCRIPT_DIR/tests")
RTL_FOLDER=$(realpath "$SCRIPT_DIR/../rtl")
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
YELLOW=$(tput setaf 3)
RESET=$(tput sgr0)

# Variables
total=0
passes=0
fails=0

# --- CHANGE: Find all *_tb.cpp files ---
# This excludes verify.cpp automatically based on naming convention
files=(${TEST_FOLDER}/*_tb.cpp)
# --------------------------------------

if [ ${#files[@]} -eq 0 ]; then
    echo "${YELLOW}No unit tests (*_tb.cpp) found in ${TEST_FOLDER}${RESET}"
    exit 0
fi

cd $SCRIPT_DIR

# Wipe previous test output
rm -rf test_out/*

echo "Found ${#files[@]} unit tests."

# Iterate through files
for file in "${files[@]}"; do
    ((total++))
    # Extract the RTL module name (e.g., ALU_tb.cpp -> ALU)
    name=$(basename "$file" _tb.cpp)

    echo "================================"
    echo "Building and Running Test: $name"
    echo "================================"

    # Gather all RTL subdirectories
    rtl_dirs=($(find "$RTL_FOLDER" -type d))

    # Build -y arguments
    y_args=()
    for d in "${rtl_dirs[@]}"; do
        y_args+=(-y "$d")
    done

    # Translate Verilog -> C++
    # Using quiet output (> /dev/null) to keep terminal clean, show errors only
    verilator -Wall --trace \
                 -cc ${RTL_FOLDER}/${name}.sv \
                 --exe ${file} \
                 "${y_args[@]}" \
                 --prefix "Vdut" \
                 -o Vdut \
                 -LDFLAGS "-lgtest -lgtest_main -lpthread" \
                 2>&1 >/dev/null

    if [ $? -ne 0 ]; then
        echo "${RED}Verilator translation failed for $name!${RESET}"
        ((fails++))
        continue
    fi

    # Build C++ project
    make -j -C obj_dir/ -f Vdut.mk >/dev/null 2>&1

    # Run executable
    ./obj_dir/Vdut

    # Check result
    if [ $? -eq 0 ]; then
        ((passes++))
        echo "${GREEN}>> Test $name PASSED${RESET}"
    else
        ((fails++))
        echo "${RED}>> Test $name FAILED${RESET}"
    fi

    # Move waveform file
    if [ -f "waveform.vcd" ]; then
        test_basename=$(basename "$file" .cpp)
        mkdir -p test_out/${test_basename}
        mv waveform.vcd test_out/${test_basename}/
    fi
    echo "" # Add newline between tests
done

# Save obj_dir
mv obj_dir test_out/ 2>/dev/null

echo "================================"
echo "Unit Test Summary"
echo "================================"
echo "Total Tests: $total"
echo "Passed: ${GREEN}$passes${RESET}"
echo "Failed: ${RED}$fails${RESET}"

if [ $fails -eq 0 ]; then
    exit 0
else
    exit 1
fi