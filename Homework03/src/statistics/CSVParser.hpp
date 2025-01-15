/* 
* Header file for CSVParser.hpp
* Declaration of a class containing methods and constructor for reading an input csv file and perform operations such as:
* Constructor for reading csv file, head and tail of the dataset, extract column values, extract headers, use header index and return a result.txt file
* Uses Boost as auxiliary library to perform tokenization. 
*/

#ifndef CSVPARSER_HPP__
#define CSVPARSER_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <variant>
#include <cctype>

#include "CellType.hpp"

class CSVParser {
    
    public:

        // Constructor that accepts file path, delimiter, and whether headers are present
        explicit CSVParser(const std::string& filePath, char delimiter = ',', bool hasHeaders = true);

        // Parse the CSV file and return a 2D vector of Cell values
        std::vector<std::vector<Cell>> parse();

        // Returns the headers if present
        std::optional<std::vector<std::string>> getHeaders() const;

        // Get the index of a specific header
        int getHeaderIndex(const std::string& header) const;

        // Get the size of the csv
        int getNumRows() const;

        // Head,Tail and specific row of the csv
        std::vector<std::vector<Cell>> getHead(int count) const; 
        std::vector<std::vector<Cell>> getTail(int count) const;   
        std::optional<std::vector<Cell>> getRow(int row) const;

        //method to exctract information of a csv column
        std::vector<Cell> operator[](const std::string& columnName) const;

        // Methods to check the data type
        bool isString(const std::string& token) const;
        bool isDouble(const std::string& token) const;
        bool isInteger(const std::string& token) const;

    private:

        std::string filePath;               
        char delimiter;                     
        bool hasHeaders;                    
        std::optional<std::vector<std::string>> headers; 
        std::vector<std::vector<Cell>> data; 

};

#endif // CSVPARSER_HPP__