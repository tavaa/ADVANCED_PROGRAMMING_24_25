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

#include "../../src/statistics/CSVParser.hpp"
#include "../../src/statistics/Statistics.hpp"
#include "../../src/statistics/CellType.hpp"

int main() {

    std::string filePath = "../datasets/";
    std::string fileName = "gym_members_exercise_tracking.csv";
    filePath += fileName;
    
    CSVParser dataset(filePath, ',', true);
    auto data = dataset.parse();

    //example calculate mean of age column
    std::vector<Cell>  column_values_age = dataset["Age"]; 
    double mean_age = Statistics::calculateMean(column_values_age);
    std::cout << "The average age is: " << mean_age << " years." << std::endl;

    //example of calculating median
    std::vector<Cell> session_duration = dataset["Session_Duration_(hours)"];
    double median_session_duration = Statistics::calculateMedian(session_duration);
    std::cout << "The median of Workout session duration is: " << median_session_duration << " hours." <<std::endl;

    // calculate variance and sd
    std::vector<Cell> Max_BPM_Values = dataset["Max_BPM"];
    double var_Max_BPM = Statistics::calculateVariance(Max_BPM_Values);
    double std_Max_BPM = Statistics::calculateSd(Max_BPM_Values);

    std::cout << "The variance of Max BPM is: " << var_Max_BPM << " and S.D. = " << std_Max_BPM <<std::endl;
    
    //calculation of correlation coefficent for age and Max_BPM
    double p_xy = Statistics::calculateCorrelation(column_values_age, Max_BPM_Values);
    std::cout << "The correlation coefficent between Age and Max BPM is: " << p_xy << std::endl;

    //example of frequency count on qualitative variable:
    std::vector<Cell> Workout_type = dataset["Workout_Type"];
    auto freq_map_workout_type = Statistics::frequencyCount(Workout_type);

    std::cout << "Occourences for Workout type: "  << std::endl;
    for (const auto& pair : freq_map_workout_type) {   
        std::cout << pair.first << " - " << pair.second << std::endl;
    }

    return 0;
}