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

std::string filePath = "../../datasets/gym_members_exercise_tracking.csv";

void testParseCSV() {
    CSVParser parser(filePath, ',', true);
    try {
        auto data = parser.parse();
        std::cout << "CSV parsed successfully with " << data.size() << " rows." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "testParseCSV: Exception - " << e.what() << "\n";
    }
}

void testGetHeaders() {
    CSVParser parser(filePath, ',', true);
    auto data = parser.parse();
    try {
        auto headers = parser.getHeaders();
        if (headers) {
            std::cout << "Headers: \n";
            for (const auto& header : *headers) {
                std::cout << header << " \n";
            }
        } else {
            std::cerr << "No headers found." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "testGetHeaders: Exception - " << e.what() << "\n";
    }
}

void testGetHead() {
    CSVParser parser(filePath, ',', true);
    auto data = parser.parse();
    try {
        auto head = parser.getHead(5);
        std::cout << "First 5 rows:" << std::endl;
        for (const auto& row : head) {
            for (const auto& cell : row) {
                std::visit([](auto& value) { std::cout << value << " "; }, *cell);
            }
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "testGetHead: Exception - " << e.what() << "\n";
    }
}

void testGetTail() {
    CSVParser parser(filePath, ',', true);
    auto data = parser.parse();
    try {
        auto tail = parser.getTail(5);
        std::cout << "Last 5 rows:" << std::endl;
        for (const auto& row : tail) {
            for (const auto& cell : row) {
                std::visit([](auto& value) { std::cout << value << " "; }, *cell);
            }
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "testGetTail: Exception - " << e.what() << "\n";
    }
}

void testGetRow() {
    CSVParser parser(filePath, ',', true);
    auto data = parser.parse();
    try {
        auto row = parser.getRow(2);
        if (row) {
            std::cout << "Row 2: ";
            for (const auto& cell : *row) {
                std::visit([](auto& value) { std::cout << value << " "; }, *cell);
            }
            std::cout << std::endl;
        } else {
            std::cerr << "Row not found." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "testGetRow: Exception - " << e.what() << "\n";
    }
}

void testGetColumn() {
    CSVParser parser(filePath, ',', true);
    auto data = parser.parse();
    try {
        auto column = parser["Resting_BPM"];
        std::cout << "Column1 values: \n";
        for (const auto& cell : column) {
            std::visit([](auto& value) { std::cout << value << " "; }, *cell);
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "testGetColumn: Exception - " << e.what() << "\n";
    }
}

int main() {
    std::cout << "Testing CSVParser Module\n";

    testParseCSV();
    std::cout << "\n" << std::endl;
    testGetHeaders();
    std::cout << "\n" << std::endl;
    testGetHead();
    std::cout << "\n" << std::endl;
    testGetTail();
    std::cout << "\n" << std::endl;
    testGetRow();
    std::cout << "\n" << std::endl;
    testGetColumn();

    return 0;
}
