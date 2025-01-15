#!/bin/bash

run_tests_with_delay() {
    python -m unittest "$1"
    sleep 2  
}

run_tests_with_delay "test_CSVParser.py"
run_tests_with_delay "test_statistics.py"
run_tests_with_delay "test_integration.py"

echo "All test have been ran!"