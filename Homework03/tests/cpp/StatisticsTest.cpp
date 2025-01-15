/*
* Test for the Statistical Module.
* Implements also the CSVParser module to parse an example csv (default = "gym_members_exercise_tracking.csv") and CellType header.
* Mission: test the funtionalities and the error handling.
*/

#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <optional>
#include <sstream>
#include <fstream>

#include "../../src/statistics/CSVParser.hpp"
#include "../../src/statistics/Statistics.hpp"
#include "../../src/statistics/CellType.hpp"

std::string filePath = "../../datasets/gym_members_exercise_tracking.csv";
std::string outputPath = "../../output/statistics/";

void testMinValue() {
    Statistics stats(filePath, ',', true);
    auto column = stats.getColumn("Age");
    if (column) {
        try {
            double minValue = stats.minValue(*column);
            std::cout << "Min Value: " << minValue << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "testMinValue: Exception - " << e.what() << "\n";
        }
    } else {
        std::cerr << "Column not found." << std::endl;
    }
}

void testMaxValue() {
    Statistics stats(filePath, ',', true);
    auto column = stats.getColumn("Age");
    if (column) {
        try {
            double maxValue = stats.maxValue(*column);
            std::cout << "Max Value: " << maxValue << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "testMaxValue: Exception - " << e.what() << "\n";
        }
    } else {
        std::cerr << "Column not found." << std::endl;
    }
}

void testCalculateMean() {
    Statistics stats(filePath, ',', true);
    auto column = stats.getColumn("Age");
    if (column) {
        try {
            double mean = stats.calculateMean(*column);
            std::cout << "Mean: " << mean << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "testCalculateMean: Exception - " << e.what() << "\n";
        }
    } else {
        std::cerr << "Column not found." << std::endl;
    }
}

void testCalculateMedian() {
    Statistics stats(filePath, ',', true);
    auto column = stats.getColumn("Age");
    if (column) {
        try {
            double median = stats.calculateMedian(*column);
            std::cout << "Median: " << median << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "testCalculateMedian: Exception - " << e.what() << "\n";
        }
    } else {
        std::cerr << "Column not found." << std::endl;
    }
}

void testCalculateVariance() {
    Statistics stats(filePath, ',', true);
    auto column = stats.getColumn("Age");
    if (column) {
        try {
            double variance = stats.calculateVariance(*column);
            std::cout << "Variance: " << variance << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "testCalculateVariance: Exception - " << e.what() << "\n";
        }
    } else {
        std::cerr << "Column not found." << std::endl;
    }
}

void testCalculateSd() {
    Statistics stats(filePath, ',', true);
    auto column = stats.getColumn("Age");
    if (column) {
        try {
            double sd = stats.calculateSd(*column);
            std::cout << "Standard Deviation: " << sd << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "testCalculateSd: Exception - " << e.what() << "\n";
        }
    } else {
        std::cerr << "Column not found." << std::endl;
    }
}

void testFrequencyCount() {
    Statistics stats(filePath, ',', true);
    auto column = stats.getColumn("Gender");
    if (column) {
        try {
            auto freqCount = stats.frequencyCount(*column);
            std::cout << "Frequency Count:\n";
            for (const auto& [key, value] : freqCount) {
                std::cout << key << ": " << value << "\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "testFrequencyCount: Exception - " << e.what() << "\n";
        }
    } else {
        std::cerr << "Column not found." << std::endl;
    }
}

void testDrawHistogram() {
    Statistics stats(filePath, ',', true);
    auto column = stats.getColumn("Workout_Type");
    if (column) {
        try {
            std::ofstream outFile(outputPath + "histogram.txt");
            stats.drawHistogram(*column, outFile);
            outFile.close();
            std::cout << "Histogram written to histogram.txt" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "testDrawHistogram: Exception - " << e.what() << "\n";
        }
    } else {
        std::cerr << "Column not found." << std::endl;
    }
}

int main() {
    std::cout << "Testing Statistics Methods\n";

    testMinValue();
    testMaxValue();
    testCalculateMean();
    testCalculateMedian();
    testCalculateVariance();
    testCalculateSd();
    testFrequencyCount();
    //testDrawHistogram();

    return 0;
}