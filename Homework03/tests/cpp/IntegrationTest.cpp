/*
* Test for the Integration Module.
* Mission: test the funtionalities and the error handling.
*/

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <functional>

#include "../../src/integration/Integration.hpp"

// Test utility to compare floating-point numbers
bool almostEqual(double a, double b, double tolerance = 1e-6) {
    return std::fabs(a - b) < tolerance;
}

// Test cases for Step size class
void testStepSize() {
    Integration integrator;
    try {
        double step = integrator.stepSize(0, 1, 10);
        if (!almostEqual(step, 0.1)) {
            std::cerr << "testStepSize: Failed (Expected 0.1, got " << step << ")\n";
        } else {
            std::cout << "testStepSize: Passed\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "testStepSize: Exception - " << e.what() << "\n";
    }

    try {
        integrator.stepSize(0, 1, 0); // Should throw
        std::cerr << "testStepSize: Failed (No exception for N <= 0)\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "testStepSize: Passed exception case (N <= 0)\n";
    }
}

// Test for Midpoint rule
void testMidpointRule() {
    Integration integrator;
    auto f = [](double x) { return x * x; }; // f(x) = x^2

    try {
        double result = integrator.midpointRule(f, 0, 1, 10);
        if (!almostEqual(result, 0.333333, 1e-5)) {
            std::cerr << "testMidpointRule: Failed (Expected ~0.333333, got " << result << ")\n";
        } else {
            std::cout << "testMidpointRule: Passed\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "testMidpointRule: Exception - " << e.what() << "\n";
    }

    try {
        integrator.midpointRule(nullptr, 0, 1, 10); // Should throw
        std::cerr << "testMidpointRule: Failed (No exception for nullptr function)\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "testMidpointRule: Passed exception case (nullptr function)\n";
    }
}

// Test for Trapezoidal rule
void testTrapezoidalRule() {
    Integration integrator;
    auto f = [](double x) { return x; }; // f(x) = x

    try {
        double result = integrator.trapezoidalRule(f, 0, 1, 10);
        if (!almostEqual(result, 0.5)) {
            std::cerr << "testTrapezoidalRule: Failed (Expected 0.5, got " << result << ")\n";
        } else {
            std::cout << "testTrapezoidalRule: Passed\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "testTrapezoidalRule: Exception - " << e.what() << "\n";
    }
}

// Test for Trapezoidal rule
void testSimpsonsRule() {
    Integration integrator;
    auto f = [](double x) { return x * x; }; // f(x) = x^2

    try {
        double result = integrator.simpsonsRule(f, 0, 1, 10);
        if (!almostEqual(result, 0.333333, 1e-5)) {
            std::cerr << "testSimpsonsRule: Failed (Expected ~0.333333, got " << result << ")\n";
        } else {
            std::cout << "testSimpsonsRule: Passed\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "testSimpsonsRule: Exception - " << e.what() << "\n";
    }

    try {
        integrator.simpsonsRule(f, 0, 1, 11); // Should throw
        std::cerr << "testSimpsonsRule: Failed (No exception for odd N)\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "testSimpsonsRule: Passed exception case (odd N)\n";
    }
}

int main() {
    std::cout << "Running Integration Tests...\n";
    
    testStepSize();
    testMidpointRule();
    testTrapezoidalRule();
    testSimpsonsRule();

    std::cout << "All tests completed.\n";
    return 0;
}