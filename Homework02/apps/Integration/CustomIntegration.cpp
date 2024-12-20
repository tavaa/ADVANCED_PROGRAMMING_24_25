/*
* Application for the Integration module.
* Uses MuParserX to parse an expression.
* Ask the user to insert a custom function, two extremes of integration, N. of intervals and the method of approximation
* Return into a txt file the summary of the operation and the result of the operations.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

#include "../../include/muparserx-4.0.12/parser/mpParser.h"
#include "../../src/integration/Integration.hpp"

double evaluateFunction(const std::string& expr, double x) {
    mup::ParserX parser;
    mup::Value valX(x);

    parser.DefineVar("x", mup::Variable(&valX));
    parser.SetExpr(expr);

    return parser.Eval().GetFloat();
}

int main(int argc, char* argv[]) {

    if (argc != 6) {
        std::cerr << "Usage: " << argv[0] 
                  << " <function> <lower_bound> <upper_bound> <N> <method>" 
                  << std::endl;
        return 1;
    }

    std::string expression = argv[1];
    double a = std::stod(argv[2]);
    double b = std::stod(argv[3]);
    int N = std::stoi(argv[4]);
    std::string method = argv[5];

    try {
        
        auto f = [&expression](double x) {
            return evaluateFunction(expression, x);
        };

        Integration integration;

        double result = 0.0;
        if (method == "midpoint") {
            result = integration.midpointRule(f, a, b, N);
        } else if (method == "trapezoidal") {
            result = integration.trapezoidalRule(f, a, b, N);
        } else if (method == "simpson") {
            result = integration.simpsonsRule(f, a, b, N);
        } else {
            std::cerr << "Not valid method. Use 'midpoint', 'trapezoidal' o 'simpson'." << std::endl;
            return 1;
        }

        std::ofstream outputFile("../output/integration/IntegrationResult.txt");
        if (!outputFile) {
            std::cerr << "Error impossible to create output file." << std::endl;
            return 1;
        }

        outputFile << "RESULTS of INTEGRATION" << "\n";
        outputFile << "-------------------------------------------" << std::endl;
        outputFile << "Function: " << expression << "\n";
        outputFile << "Lower Bound (a): " << a << "\n";
        outputFile << "Upper Bound (b): " << b << "\n";
        outputFile << "Number of Intervals (N): " << N << "\n";
        outputFile << "Integration method: " << method << "\n";
        outputFile << "Result of approximation: " << result << "\n";

        outputFile.close();

        std::cout << "Result saved in 'IntegrationResult.txt'." << std::endl;

        std::cout << "Result of the integration with method " << method << ": " << result << std::endl;

    } catch (const mup::ParserError& e) {
        std::cerr << "Error while parsing the function: " << e.GetMsg() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

