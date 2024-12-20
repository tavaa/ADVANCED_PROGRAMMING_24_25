/*
* Application on the student dataset.
*/

#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <optional>
#include <sstream>
#include <algorithm> 
#include <fstream>
#include <iomanip>

#include "../../src/statistics/CSVParser.hpp"
#include "../../src/statistics/Statistics.hpp"
#include "../../src/statistics/CellType.hpp"

// help functions to use in the analysis
double calculateStatsCategory(const std::vector<Cell> &colummValues1, const std::vector<Cell> &colummValues2, int category, std::string analysis_type){

    std::vector<Cell> category_values;
    int new_current_value = 0;

    for (size_t i = 0; i < colummValues1.size(); ++i) {
        try {
            new_current_value = Statistics::toNumeric(colummValues1[i]); // gender: 0/1
            if (new_current_value == category){  // new_current_value: matches category wanted
                category_values.push_back(colummValues2[i]); // add reading_score value to the new vector
            }
        } catch (...) {
            continue;
        }
    }

    double result = 0.0;
    if (analysis_type == "mean")
        result = Statistics::calculateMean(category_values);
    else if (analysis_type == "median")
        result = Statistics::calculateMedian(category_values);
    else
        std::cout << "Other analysis...";

    return result;
    
}

// help function to use in the analysis
double calculateStatsCategory(const std::vector<Cell> &colummValues1, const std::vector<Cell> &colummValues2, std::string category, std::string analysis_type){

    // colValues1 = x_scores
    // colValues2 = parental education

    std::vector<Cell> category_values;
    std::string new_current_value;

    for (size_t i = 0; i < colummValues2.size(); ++i) {
        try {
            new_current_value = Statistics::toString(colummValues2[i]); 
            if (new_current_value == category){  
                category_values.push_back(colummValues1[i]); 
            }
        } catch (...) {
            continue;
        }
    }

    double result = 0.0;
    if (analysis_type == "mean")
        result = Statistics::calculateMean(category_values);
    else if (analysis_type == "median")
        result = Statistics::calculateMedian(category_values);
    else
        std::cout << "Other analysis...";

    return result;
    
}

int main() {

    std::string filePath = "../datasets/";
    std::string fileName = "Cleaned_Students_Performance"; 
    std::ofstream outputFile("../output/statistics/" + fileName + "_results.txt");
    fileName += ".csv";
    filePath += fileName;

    if (!outputFile.is_open()) {
        std::cerr << "Error while opening output file!" << std::endl;
        return 1;
    }
    
    // Parse the dataset
    CSVParser dataset_students(filePath, ',', true);
    auto data = dataset_students.parse();
    
    // Writing dataset information to the output file
    outputFile << "-------------------------------------------" << std::endl;
    outputFile << "STUDENT PERFORMANCE DATASET" << std::endl;
    outputFile << "-------------------------------------------" << std::endl;

    auto headers_dataset = dataset_students.getHeaders();
    std::string headers_list = "List of the index and headers in the csv (tokenized):\n";
    int index;

    for (const auto &head : *headers_dataset) {
        index = dataset_students.getHeaderIndex(head);
        headers_list += std::to_string(index) + " - " + head + ".\n";  // Concatenate header with newline
    }

    // Relevant information about the dataset
    int dataset_size = dataset_students.getNumRows();
    outputFile << "Dataset size: (" << dataset_size << ", " << std::to_string(index + 1) << ")." << std::endl;
    outputFile << "-------------------------------------------" << std::endl;

    // Print the headers list
    outputFile << headers_list;
    outputFile << "-------------------------------------------" << std::endl;

    // Print the first 5 rows of the CSV data for preliminary analysis
    outputFile << "\nFirst 5 rows of the data:\n";
    std::vector<std::vector<Cell>> headlines = dataset_students.getHead(5);

    for (const auto& row : headlines) {
        for (const auto& cell : row) {
            if (cell.has_value()) {
                std::visit([&outputFile](const auto& value) {
                    outputFile << value << " ";
                }, *cell);  
            } else {
                outputFile << "N/A ";  
            }
        }
        outputFile << "\n";
    }
    outputFile << "-------------------------------------------" << std::endl;

    // Print the first 5 rows of the CSV data for preliminary analysis
    outputFile << "\nLast 5 rows of the data:\n";
    std::vector<std::vector<Cell>> taillines = dataset_students.getTail(5);

    for (const auto& row : taillines) {
        for (const auto& cell : row) {
            if (cell.has_value()) {
                std::visit([&outputFile](const auto& value) {
                    outputFile << value << " ";
                }, *cell);  
            } else {
                outputFile << "N/A ";  
            }
        }
        outputFile << "\n";
    }

    outputFile << "-------------------------------------------" << std::endl;
    outputFile << "\n";

    // Extrapolate column values
    std::vector<Cell> gender = dataset_students["gender"];
    std::vector<Cell> race_ethnicity = dataset_students["race_ethnicity"];
    std::vector<Cell> parental_level_of_education = dataset_students["parental_level_of_education"];
    std::vector<Cell> lunch = dataset_students["lunch"];
    std::vector<Cell> test_preparation_course = dataset_students["test_preparation_course"];
    
    // Quantitative columns
    std::vector<Cell> math_score = dataset_students["math_score"];
    std::vector<Cell> reading_score = dataset_students["reading_score"];
    std::vector<Cell> writing_score = dataset_students["writing_score"];
    std::vector<Cell> total_score = dataset_students["total_score"];
    std::vector<Cell> average_score = dataset_students["average_score"];

    // Obtain statistical values into vectors for quantitative variables
    std::vector<double> math_score_vector = {
        Statistics::minValue(math_score),
        Statistics::maxValue(math_score),
        Statistics::calculateMean(math_score),
        Statistics::calculateMedian(math_score),
        Statistics::calculateVariance(math_score),
        Statistics::calculateSd(math_score),
    };
    std::vector<double> reading_score_vector = {
        Statistics::minValue(reading_score),
        Statistics::maxValue(reading_score),
        Statistics::calculateMean(reading_score),
        Statistics::calculateMedian(reading_score),
        Statistics::calculateVariance(reading_score),
        Statistics::calculateSd(reading_score),
    };
    std::vector<double> writing_score_vector = {
        Statistics::minValue(writing_score),
        Statistics::maxValue(writing_score),
        Statistics::calculateMean(writing_score),
        Statistics::calculateMedian(writing_score),
        Statistics::calculateVariance(writing_score),
        Statistics::calculateSd(writing_score),
    };
    std::vector<double> tot_score_vector = {
        Statistics::minValue(total_score),
        Statistics::maxValue(total_score),
        Statistics::calculateMean(total_score),
        Statistics::calculateMedian(total_score),
        Statistics::calculateVariance(total_score),
        Statistics::calculateSd(total_score),
    };
    std::vector<double> avg_score_vector = {
        Statistics::minValue(average_score),
        Statistics::maxValue(average_score),
        Statistics::calculateMean(average_score),
        Statistics::calculateMedian(average_score),
        Statistics::calculateVariance(average_score),
        Statistics::calculateSd(average_score),
    };

    // Function to print vector to the output file
    auto print_vector = [&outputFile](const std::vector<double>& vec, const std::string& name) {
        outputFile << name << ": ";
        for (const auto& value : vec) {
            outputFile << value << " | ";
        }
        outputFile << "\n";
    };

    // Print the statistics for the quantitative variables
    outputFile << "Main statistics: min | max | mean | median | variance | std |" << std::endl;
    print_vector(math_score_vector, "Math Score: ");
    print_vector(reading_score_vector, "Reading Score: ");
    print_vector(writing_score_vector, "Writing Score: ");
    print_vector(tot_score_vector, "Total Score: ");
    print_vector(avg_score_vector, "Average Score: ");
    outputFile << "-------------------------------------------" << std::endl;

    //qualitative variables analysis
    outputFile << "Frequency maps of boolean variables: " << std::endl;
    outputFile << "\n";

    outputFile << "Gender: " << std::endl;
    auto freqMap_gender = Statistics::frequencyCount(gender);
    for (const auto& pair : freqMap_gender) {   
        outputFile << std::stoi(pair.first) << " - " << pair.second << std::endl;
    }
    outputFile << "-------------------------------------------" << std::endl;
    
    outputFile << "Lunch: " << std::endl;
    auto freqMap_lunch = Statistics::frequencyCount(lunch);
    for (const auto& pair : freqMap_lunch) {   
        outputFile << std::stoi(pair.first) << " - " << pair.second << std::endl;
    }
    outputFile << "-------------------------------------------" << std::endl;
    
    outputFile << "Test preparation course: " << std::endl;
    auto freqMap_test_preparation_course = Statistics::frequencyCount(test_preparation_course);
    for (const auto& pair : freqMap_test_preparation_course) {   
        outputFile<< std::stoi(pair.first) << " - " << pair.second << std::endl;
    }
    outputFile << "-------------------------------------------" << std::endl;
    outputFile << "Plotting histograms of qualitative variables: " << std::endl;
    outputFile << "\n";

    outputFile << "Race ethnicity: " << std::endl;
    Statistics::drawHistogram(race_ethnicity, outputFile);
    outputFile << "-------------------------------------------" << std::endl;
    outputFile << "Parental level of education: " << std::endl;
    Statistics::drawHistogram(parental_level_of_education, outputFile);
    outputFile << "-------------------------------------------" << std::endl;
    outputFile << "\n";

    outputFile << "Two questions to explore the correlation in the dataset: " << std::endl;
    outputFile << "\n";
    outputFile << "1. Is there a relationship between math score and reading score? " << std::endl;
    outputFile << "2. Is there a relationship between writing score and total score? " << std::endl;
    outputFile << "\n";

    double p_xy_math_reading = Statistics::calculateCorrelation(math_score, reading_score);

    std::string correlation_1;
    if (p_xy_math_reading > 0 ) {
        correlation_1 = "Positive.";
    } else if (p_xy_math_reading == 0) {
        correlation_1 = " Neutral.";
    } else {
        correlation_1 = "Negative.";
    }

    outputFile << "1. p_xy(math_score, reading_score): " << std::to_string(p_xy_math_reading) << " -> " << correlation_1 << std::endl;

    double p_xy_writing_total = Statistics::calculateCorrelation(writing_score, total_score);

    std::string correlation_2;
    if (p_xy_writing_total > 0 ) {
        correlation_2 = "Positive.";
    } else if (p_xy_writing_total == 0) {
        correlation_2 = " Neutral.";
    } else {
        correlation_2 = "Negative.";
    }

    outputFile << "2. p_xy(writing_score, total_score): " << std::to_string(p_xy_writing_total) << " -> " << correlation_2 << std::endl;
    outputFile << "\n";

    outputFile << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    outputFile << "|  PERFORMANCE BY GENDER                                                                 |" << std::endl;    
    outputFile << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    outputFile << std::endl;

    std::vector<std::string> scores = {"math_score","reading_score", "writing_score", "total_score","average_score"};
    const int colWidth = 15;
    const int col1Width = 15;

    // print table headers
    outputFile << std::left << std::setw(col1Width) << "";
    for (const auto& score : scores){
        outputFile << std::setw(colWidth) << score;
    }
    outputFile << std::endl;

    // Print separator line
    outputFile << std::string(col1Width + colWidth * 5, '-') << std::endl;

    for (int i = 0; i < 2; i++){
        if (i == 0) outputFile << std::left << std::setw(col1Width) << "Male";
        else outputFile << std::left << std::setw(col1Width) << "Female";

        for (auto &score: scores){
            outputFile << std::setw(colWidth) << calculateStatsCategory(gender,dataset_students[score],i,"mean");
        }
        outputFile << std::endl;
    }

    outputFile << std::endl;
    outputFile << "\n";

    outputFile << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    outputFile << "|  IMPACT OF PARENTAL EDUCATION                                                                                        |" << std::endl;                                                                        
    outputFile << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    outputFile << std::endl;

    std::vector<std::string> education = {"bachelor's_degree", "some_college", "high_school", "associate's_degree", "master's_degree"};
   
    std::vector<std::vector<double>> table(education.size(), std::vector<double>(scores.size()));

    // load table
    for (size_t i = 0; i < education.size(); i++){
        for (size_t j = 0; j < scores.size(); j++){
            table[i][j] = calculateStatsCategory(dataset_students[scores[j]],parental_level_of_education, education[i], "mean");
        }
    }

    const int col1Width2 = 20;
    const int colWidth2 = 20;

    // print table headers
    outputFile << std::left << std::setw(col1Width2) << "";
    for (const auto& score : scores){
        outputFile << std::setw(colWidth2) << score;
    }
    outputFile << std::endl;

    // Print separator line
    outputFile << std::string(col1Width2 + colWidth2 * 5, '-') << std::endl;

    // print table row
    for (size_t i = 0; i < education.size(); i++){
        outputFile << std::left << std::setw(col1Width2) << education[i];
        for (size_t j = 0; j < scores.size(); j++){
            outputFile << std::setw(colWidth2) << table[i][j];
        }
        outputFile << std::endl;
    }

    outputFile << std::endl;
    outputFile << "\n";

    outputFile << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    outputFile << "|  IMPACT OF TEST PREPARATION                                                            |" << std::endl;  
    outputFile << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    outputFile << std::endl;

    // print table headers
    outputFile << std::left << std::setw(col1Width) << "Test completed?";
    for (const auto& score : scores){
        outputFile << std::setw(colWidth) << score;
    }
    outputFile << std::endl;

    // Print separator line
    outputFile << std::string(col1Width + colWidth * 5, '-') << std::endl;

    for (int i = 0; i < 2; i++){
        if (i == 0) outputFile << std::left << std::setw(col1Width) << "No";
        else outputFile << std::left << std::setw(col1Width) << "Yes";

        for (auto &score: scores){
            outputFile << std::setw(colWidth) << calculateStatsCategory(test_preparation_course,dataset_students[score],i,"mean");
        }
        outputFile << std::endl;
    }

    outputFile << std::endl;
    outputFile << "\n";

    outputFile << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    outputFile << "|  SCORE DISTRIBUTION BY RACE                                                            |" << std::endl;  
    outputFile << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    outputFile << std::endl;

    std::vector<std::string> group = {"group_A", "group_B", "group_C", "group_D", "group_E"};

    std::vector<std::vector<double>> table2(group.size(), std::vector<double>(scores.size()));

    // load table
    for (size_t i = 0; i < group.size(); i++){
        for (size_t j = 0; j < scores.size(); j++){
            table2[i][j] = calculateStatsCategory(dataset_students[scores[j]],race_ethnicity, group[i], "mean");
        }
    }

    // print table headers
    outputFile << std::left << std::setw(col1Width) << "";
    for (const auto& score : scores){
        outputFile << std::setw(colWidth) << score;
    }
    outputFile << std::endl;

    // Print separator line
    outputFile << std::string(col1Width + colWidth * 5, '-') << std::endl;

    // print table row
    for (size_t i = 0; i < group.size(); i++){
        outputFile << std::left << std::setw(col1Width) << group[i];
        for (size_t j = 0; j < scores.size(); j++){
            outputFile << std::setw(colWidth) << table2[i][j];
        }
        outputFile << std::endl;
    }

    outputFile << std::endl;
    outputFile << "\n";

    // Close the output file
    outputFile.close();

    return 0;
}

    