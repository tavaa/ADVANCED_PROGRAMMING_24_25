/*
* Script for custom Analysis.
* Complete the script using apps/student_analysis
*/

#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <optional>
#include <sstream>
#include <algorithm> 
#include <fstream>
 
#include "../../src/statistics/CSVParser.hpp"
#include "../../src/statistics/Statistics.hpp"
#include "../../src/statistics/CellType.hpp"

int main() {

    std::string filePath = "../datasets/";
    std::string fileName = "csv_to_analyze";
    fileName += ".csv";
    filePath += fileName;
    
    // Output file stream to write results
    std::ofstream outputFile("../output/statistics/" + fileName + "_results.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Error while opening output file!" << std::endl;
        return 1;
    }

    CSVParser dataset_to_analyze(filePath, ',', true);
    //auto data = dataset_to_analyze.parse();

    return 0;
}