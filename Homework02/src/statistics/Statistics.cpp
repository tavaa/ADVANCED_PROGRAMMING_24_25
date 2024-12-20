/* 
* Implementation file for Statistics.cpp
* Implementation of a class containing methods and constructor for statistical analyses on custom csv
* Includes methods and operations within the class to calculate mean, median, s.d, variance, freq. count, classification.
* Return the output into a txt file
*/

#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <variant>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>

#include "CellType.hpp"
#include "Statistics.hpp"

/*
* Helper function to convert cell to Numeric
* @param cell: cell to convert
* @throws invalid_argument exception if cell is N/A or if not numeric
* @return converted cell
*/
double Statistics::toNumeric(const Cell& cell){

    if (!cell.has_value()) {
        throw std::invalid_argument("Cell is N/A!");
    } else {
        
        if(std::holds_alternative<int>(*cell)){
            return static_cast<double>(std::get<int>(*cell));
        } else if (std::holds_alternative<double>(*cell)) {
            return std::get<double>(*cell);
        } else {
            throw std::invalid_argument("Cell is not numeric!");
        }
    }
}

/*
* Helper function to convert a cell to String
* @param cell: cell to convert 
* @throws invalid_argument exception if cell is invalid
* @return converted cell
*/
std::string Statistics::toString(const Cell& cell) {

    if (!cell.has_value()) {
        return "null";
    } else {

        if (std::holds_alternative<std::string>(*cell)) {
            return std::get<std::string>(*cell);
        } else if (std::holds_alternative<int>(*cell)) {
            return std::to_string(std::get<int>(*cell));
        } else if (std::holds_alternative<double>(*cell)) {
            return std::to_string(std::get<double>(*cell));
        } else {
            throw std::invalid_argument("invalid Cell type!");
        }
    }
}

/*
* Method to calculate min
* @param columnValues: values inside a column of CSV
* @throws std::runtime_error: if no numerical data
* @return min: minimum value
*/
double Statistics::minValue(const std::vector<Cell>& columnValues) {

    double min = std::numeric_limits<double>::infinity();  
    bool hasValidData = false;

    for (const auto &value : columnValues) {

        try {
            double numericValue = toNumeric(value);
            if (numericValue < min) {
                min = numericValue;
            }
            hasValidData = true;
        } catch (...) {
            continue;  
        }
    }

    if (!hasValidData) {
        throw std::runtime_error("No numerical data!");  
    }

    return min;
}

/*
* Method to calculate max
* @param columnValues: values inside a column of CSV
* @throws std::runtime_error: if no numerical data
* @return max: maximum value
*/
double Statistics::maxValue(const std::vector<Cell>& columnValues) {

    double max = -std::numeric_limits<double>::infinity();  
    bool hasValidData = false;

    for (const auto &value : columnValues) {

        try {
            double numericValue = toNumeric(value);
            if (numericValue > max) {
                max = numericValue;
            }
            hasValidData = true;
        } catch (...) {
            continue;  
        }
    }

    if (!hasValidData) {
        throw std::runtime_error("No numerical data!");  
    }

    return max;
}


/*
* Method to calculate the mean of a column 
* @param columnValues: values to pass inside a column of a csv
* @throws run_time_error: if it is not possible to compute mean (categorical)
* @return mean: mean of the values
*
*/
double Statistics::calculateMean(const std::vector<Cell> &columnValues) {

    double sum = 0.0;
    double mean = 0.0;
    int count = 0;

    for (const auto &value: columnValues) {

        try {
            sum += toNumeric(value);
            ++count;
        } catch (...){
            continue;
        }
    }

    if (count == 0) throw std::runtime_error("No numerical data!");
    mean = sum/count;
    return mean;
}

/*
* Method to calculate the median of a column 
* @param columnValues: values to pass inside a column of a csv
* @throws run_time_error: if it is not possible to compute median (categorical)
* @return median: median of the values
*/
double Statistics::calculateMedian(const std::vector<Cell> &columnValues) {

    std::vector<double> numericData;

    for (const auto &cell : columnValues) {

        try {
            numericData.push_back(toNumeric(cell));
        } catch (...){
            continue;
        } 
    }

    if (numericData.empty()) { 
        throw std::runtime_error("No numerical data!");
    } else {

        std::sort(numericData.begin(), numericData.end());
        size_t data_size = numericData.size();

        if ((data_size % 2) == 0)  {
            return ((numericData[data_size/2 -1] + numericData[data_size/2]) / 2.0);
        } else {
            return (numericData[data_size/2]);
        }
    }
}

/*
* Method to calculate the variance of a column 
* @param columnValues: values to pass inside a column of a csv
* @throws run_time_error: if it is not possible to compute variance (categorical)
* or if there are <= 1 quantitative values into vector
* @return variance: variance of the values
*/
double Statistics::calculateVariance(const std::vector<Cell> &columnValues) {

    double mean = calculateMean(columnValues);
    double sumSquaredDiff = 0.0;
    int count = 0;

    for (const auto& cell : columnValues) {
        try {
            double value = toNumeric(cell);
            sumSquaredDiff += (value - mean) * (value - mean);
            ++count;
        } catch (...) {
            continue;
        }
    }
    if (count <= 1) throw std::runtime_error("Not enough numeric values in data");
    return sumSquaredDiff / (count - 1);

}

/*
* Method to calculate the s.d. of a column 
* @param columnValues: values to pass inside a column of a csv
* @throws run_time_error: if it is not possible to compute s.d. (categorical)
* or if there are <= 1 quantitative values into vector
* @return s.d.: s.d. of the values
*/
double Statistics::calculateSd(const std::vector<Cell>& data) {
    return std::sqrt(calculateVariance(data));
}

/*
* Method to obtain the frequency count of a column of csv
* both for quantitative and qualitative variables
* @param columnValues: values to pass inside a column of a csv
* @return result: unordered_map of <values, freq.> for each observation
*/
std::unordered_map<std::string, int> Statistics::frequencyCount(const std::vector<Cell>& columnValues){

    std::unordered_map<std::string, int> result;

    for (const auto& value : columnValues) {
        std::string key = toString(value);
        result[key] ++;
    }

    return result;
}

/*
* Method to perform correlation analysis between two columns of the csv
* @params columnValues1, columnValues2: columns of the dataset;
* @throws invalid_argument exception: iff the two columns have different size 
*         run_time exception: iff the variance is not possible to compute
* @return correlation_coefficent of the two columns 
*/
double Statistics::calculateCorrelation(const std::vector<Cell> &columnValues1, const std::vector<Cell> &columnValues2) {

    if (columnValues1.size() != columnValues2.size()){
        throw std::invalid_argument("Dataset columns must have same size!");
    } else {

        double meanCol1 = calculateMean(columnValues1);
        double meanCol2 = calculateMean(columnValues2);
        double numerator = 0.0;
        double correlation_coefficent = 0.0;
        double sumSqDiffX = 0.0;
        double sumSqDiffY = 0.0;

        for (size_t i = 0; i < columnValues1.size(); ++i) {

            try {
                double x = toNumeric(columnValues1[i]);
                double y = toNumeric(columnValues2[i]);
                numerator += (x-meanCol1) * (y-meanCol2);
                sumSqDiffX += (x-meanCol1) * (x-meanCol1);
                sumSqDiffY += (y-meanCol2) * (y-meanCol2);
            } catch (...) {
                continue;
            }
        }

        if(sumSqDiffX == 0.0 || sumSqDiffY == 0.0 ){
            throw std::runtime_error("Null variance, impossible to calculate correlation");
        } else {
            correlation_coefficent = numerator / (std::sqrt(sumSqDiffX * sumSqDiffY));
        }

        return correlation_coefficent;
    }
}

/*
* Method to draw a histogram of frequencies within the csv and output to a specified stream
* @param columnValues: values of a column
* @param out: output stream to which the histogram is written (e.g., std::cout or std::ofstream)
*/
void Statistics::drawHistogram(const std::vector<Cell> &columnValues, std::ostream& out) {

    // Get frequency count map
    auto freqMap = frequencyCount(columnValues);
    std::vector<std::string> categories;

    // Populate categories from frequency map
    for (const auto& pair : freqMap) {
        categories.push_back(pair.first);
    }

    // Create histogram using Boost.Histogram
    auto hist = boost::histogram::make_histogram(boost::histogram::axis::category<std::string>(categories));

    // Fill histogram with data
    for (const auto& pair : freqMap) {
        for (int i = 0; i < pair.second; ++i) {
            hist(pair.first);
        }
    }

    // Print histogram data to the given output stream (file or console)
    for (auto&& bin : boost::histogram::indexed(hist)) {
        out << bin.bin() << " | ";
        for (int i = 0; i < *bin; ++i) {
            if ((i % 3 ) == 0) {
                out << "*";
            }
        }
        out << " (" << *bin << ")\n";
    }
}


