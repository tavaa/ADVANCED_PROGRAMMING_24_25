/*
* Test for the CSVParser Module.
* Test futionalities to parse a custom CSV through a CLI, and extract features
* Mission: test the funtionalities and the error handling.
*/

#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <optional>
#include <sstream>

#include "../../src/statistics/CSVParser.hpp"
#include "../../src/statistics/CellType.hpp"

int main() {

    std::string filePath = "../datasets/";
    std::string fileName;

    //ask the user to insert csv file
    //std::cout << "Please enter the CSV name: ";
    std::getline(std::cin, fileName);  

    filePath += fileName;
    CSVParser dataset(filePath, ',', true);
    std::cout << "CSVParser initialized with file path: " << filePath << std::endl;
    
    // Parse the CSV file
    auto data = dataset.parse();

    //print the size of the csv
    int size = dataset.getNumRows();
    std::cout << "Size of the dataset, without headers: " << size << " rows." << std::endl;

    //print the headers names
    auto headers = dataset.getHeaders();
    std::cout << "List of the index and headers in the csv (tokenized): " << std::endl;
    int index;

    for (const auto &head : *headers) {
        index = dataset.getHeaderIndex(head);
        std::cout << index << " - " << head << ".\n"; 
    }

    // Print the first 5 rows of the CSV data 
    std::cout << "\nFirst 5 rows of the data:\n";
    std::vector<std::vector<Cell>> headlines = dataset.getHead(5);

    for (const auto& row : headlines) {

        for (const auto& cell : row) {
            if (cell.has_value()) {
                
                std::visit([](const auto& value) {
                    std::cout << value << " ";
                }, *cell);  
            } else {
                std::cout << "N/A ";  
            }
        }
        std::cout << "\n";
    }

    auto row_x = dataset.getRow(15);
    std::cout << "The 15-th row of the csv is: " << std::endl;
    for (const auto &cell : *row_x) {
        if (cell.has_value()) {
                
                std::visit([](const auto& value) {
                    std::cout << value << " ";
                }, *cell);  
            } else {
                std::cout << "N/A ";  
            }
    }
    std::cout << std::endl;

    return 0;
}