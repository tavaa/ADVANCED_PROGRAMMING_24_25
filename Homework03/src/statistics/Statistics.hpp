/* 
* Header file for Statistics.hpp
* Declaration of a class containing methods and constructor for statistical analyses on custom csv
* Includes methods and operations within the class to calculate mean, median, s.d, variance, freq. count, classification.
* Return the output into a txt file
*/

#ifndef STATISTICS_HPP__
#define STATISTICS_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <variant>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>

#include "CellType.hpp"
#include "CSVParser.hpp"

class Statistics {

    public:

        //Public constructor
        Statistics(const std::string& filePath, char delimiter = ',', bool hasHeader = true);

        // get headers of a dataset
        std::optional<std::vector<std::string>> getHeaders() const;

        // getColumn of a dataset
        std::optional<std::vector<Cell>> getColumn(const std::string& columnName) const;

        //min of a quantitative variable
        static double minValue(const std::vector<Cell> &columnValues);

        //max of a quantitative variable
        static double maxValue(const std::vector<Cell> &columnValues);

        //mean of a quantitative variable
        static double calculateMean(const std::vector<Cell> &columnValues);

        //median of quantitative variable
        static double calculateMedian(const std::vector<Cell> &columnValues);

        //variance of quantitative variable
        static double calculateVariance(const std::vector<Cell> &columnValues);

        //s.d. of quantitative variable
        static double calculateSd(const std::vector<Cell> &columnValues);

        //frequency count - both quantitative and qualitative
        static std::unordered_map<std::string, int> frequencyCount(const std::vector<Cell>& columnValues);

        //correlation Analysis
        static double calculateCorrelation(const std::vector<Cell> &columnValues1, const std::vector<Cell> &columnValues2);

        //draw histogram of a column
        static void drawHistogram(const std::vector<Cell> &columnValues, std::ostream& out);

        //cell converter to (numerical value)
        static double toNumeric(const Cell& cell);

        //convert cell to string for freq. count
        static std::string toString(const Cell& cell);

    private:

        CSVParser csvParser;
        std::vector<std::vector<Cell>> data;
        
};

#endif //STATISTICS_HPP__