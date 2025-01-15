#!/bin/bash

run_test_with_delay() {

    g++ "$1" "$2" -o "$3"
    ./$3
    echo "Test $3 completed. "
    sleep 2 
}

run_test_with_delay "CSVParserTest.cpp" "../../src/statistics/CSVParser.cpp" "test_CSVParser"
g++ StatisticsTest.cpp ../../src/statistics/Statistics.cpp ../../src/statistics/CSVParser.cpp -o test_Statistics
./test_Statistics
echo "Test Statistics completed. "
sleep 2
run_test_with_delay "IntegrationTest.cpp" "../../src/integration/Integration.cpp" "test_Integration"

rm -r test_CSVParser
rm -r test_Statistics
rm -r test_Integration



