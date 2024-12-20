/*
* Test for the Integration Module.
* Mission: test the funtionalities and the error handling.
*/

#include <iostream>
#include <cmath>

#include "../../src/integration/Integration.hpp"

//example of function
double f(double x) {
    return std::sin(x); 
}

int main() {

    Integration integration;

    // Define integration bounds and number of intervals
    double a = 0.0; 
    double b = M_PI; 
    int N = 100; 

    // Midpoint Rule
    double result_midpoint = integration.midpointRule(f, a, b, N);
    std::cout << "Midpoint Rule Result: " << result_midpoint << std::endl;

    // Trapezoidal Rule
    double result_trapezoidal = integration.trapezoidalRule(f, a, b, N);
    std::cout << "Trapezoidal Rule Result: " << result_trapezoidal << std::endl;

    // Simpson's Rule
    try {
        double result_simpson = integration.simpsonsRule(f, a, b, N);
        std::cout << "Simpson's Rule Result: " << result_simpson << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error in Simpson's Rule: " << e.what() << std::endl;
    }

}