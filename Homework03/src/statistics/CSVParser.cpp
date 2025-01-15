/* 
* Implementation file for CSVParser.cpp
* Implementation of a class containing methods and constructor for reading an input csv file and perform operations such as:
* Constructor for reading csv file, head and tail of the dataset, extract column values, extract headers, use header index and return a result.txt file
* Uses Boost as auxiliary library to perform tokenization. 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <optional>
#include <variant>
#include <cctype>
#include <sstream>
#include <algorithm>

#include "CellType.hpp"
#include "CSVParser.hpp"

//constructor of CSVParser
CSVParser::CSVParser(const std::string& filePath, char delimiter, bool hasHeaders)
    : filePath(filePath), delimiter(delimiter), hasHeaders(hasHeaders) {}

/*
* method to parse into cells the content of the csv
* @return: std::vector<std::vector<Cell>>  result of parsing
* @throws: run_time_error if failed to open
*/
std::vector<std::vector<Cell>> CSVParser::parse() {

    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    std::string line;
    bool isFirstLine = true;

    while (std::getline(file, line)) {

        std::replace(line.begin(), line.end(), ' ', '_');

        // Tokenize line using the specified delimiter
        std::vector<std::string> tokens;
        std::stringstream ss(line);
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }

        if (isFirstLine && hasHeaders) {
            headers.emplace();  
            headers->assign(tokens.begin(), tokens.end());
            isFirstLine = false;
            continue; 
        }

        std::vector<Cell> row;
        for (const auto& token : tokens) {
            if (isString(token)) {
                row.emplace_back(token);  
            } else if (isDouble(token)) {
                row.emplace_back(std::stod(token));  
            } else if(isInteger(token)){
                row.emplace_back(std::stoi(token)); 
            } else {
                row.emplace_back(std::nullopt);
            }
        }
        data.push_back(row);
    }

    file.close();
    return data;
}

/* method to get the headers of the csv file in a vector of strings
* @return: headers vector
*/
std::optional<std::vector<std::string>> CSVParser::getHeaders() const {
    return headers;
}

/*
* method to get the index of a header
* @param header: string reference to header name
* @throws run_time_error: if the CSV does not have headers
* @return index of the header, otherwise -1
*/  
int CSVParser::getHeaderIndex(const std::string& header) const {

    if (!headers) {
        throw std::runtime_error("CSV file does not have headers.");
    }

    auto it = std::find(headers->begin(), headers->end(), header);
    if (it != headers->end()) {
        return std::distance(headers->begin(), it);
    }
    return -1;
}

/*
* Getter method for the dataset size
* @return size: number of records (without header) within the csv
*/
int CSVParser::getNumRows() const {
    return data.size();
}

/*
* method to get the first `count` rows of the dataset
* @param count: number of rows to retrieve 
* @throws run_time_error: if data is empty
* @return: vector containing the first rows
*/
std::vector<std::vector<Cell>> CSVParser::getHead(int count) const {

    if (data.empty()) {
        throw std::runtime_error("Dataset is empty. Please parse the CSV first.");
    }

    return std::vector<std::vector<Cell>>(data.begin(), data.begin() + std::min(count, static_cast<int>(data.size())));
}

/*
* method to get the last `count` rows of the dataset
* @param count: number of rows to retrieve
* @throws run_time_error: if data is empty
* @return: vector containing the last rows
*/
std::vector<std::vector<Cell>> CSVParser::getTail(int count) const {

    if (data.empty()) {
        throw std::runtime_error("Dataset is empty. Please parse the CSV first.");
    }

    int totalRows = static_cast<int>(data.size());
    int startIndex = std::max(0, totalRows - count);

    return std::vector<std::vector<Cell>>(data.begin() + startIndex, data.end());
}

/*
* Method to extract a specific row within a dataset
* @param row: index of row to extract
* @throws run_time_error: if data is empty
*         out_of_range exception: if invalid index
* @return row: content of a row
*/
std::optional<std::vector<Cell>> CSVParser::getRow(int row) const {

    if (data.empty()) {
        throw std::runtime_error("Dataset is empty. Please parse the CSV first.");
    } else if (row < 0 || row >= static_cast<int>(data.size())) {
        throw std::out_of_range("Invalid index!");
    } else {
        return data[row];
    }
}

/*
* method to extract the values within a specified column of the dataframe
* @param columName: column of interest
* @throws run_time_error if column is not found
* @return columnValues: a vector of Cell containing all values in the column
*/
std::vector<Cell> CSVParser::operator[](const std::string& columnName) const {

    int columnIndex = getHeaderIndex(columnName);

    if (columnIndex == -1) {
        throw std::runtime_error("Column not found ");
    } else {

        std::vector<Cell> columnValues;

        for (const auto& row : data) {
            columnValues.push_back(row[columnIndex]);
        }

        return columnValues;
    }
}

/*
* method to check if token is a string
* @param token: token to check
* @return true iff is a string, false otherwise
*/ 
bool CSVParser::isString(const std::string& token) const {

    return std::all_of(token.begin(), token.end(), [](char c) {
        return std::isalpha(static_cast<unsigned char>(c)) || c == '_' || c == '\'';
    });
}

/*
* method to check if token is a double
* @param token: token to check
* @return true iff is a double, false otherwise
*/ 
bool CSVParser::isDouble(const std::string& token) const {
    try {
        size_t idx;
        std::stod(token, &idx);
        return idx == token.size();  
    } catch (...) {
        return false;
    }
}

/*
* method to check if token is an integer
* @param token: token to check
* @return true iff is an integer, false otherwise
*/ 
bool CSVParser::isInteger(const std::string& token) const {
    try {
        size_t idx;
        std::stoi(token, &idx);
        return idx == token.size();  
    } catch (...) {
        return false;
    }
}




