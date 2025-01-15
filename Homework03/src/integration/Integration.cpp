/* 
* Implementation file for Integration.cpp
* Implementation of a class containing methods and constructor for approximating integrals using composite numerical integration formulas.
* contains: public constructor, method to approx with midpoint rule, trapezoidal rule, Simpson rule.
*/

#include <cmath>
#include <stdexcept>
#include <functional>

#include "Integration.hpp"

/*
* Public constuctor of Integration
*/
Integration::Integration() {}

/*
* Helper function for the stepsize
* @params a,b: lower and upper bound of the intergal.
* @param N: n.of intervals
* @return step size for the interval
*/
double Integration::stepSize(double a, double b, int N) {

    if (N <= 0 ) {
        throw std::invalid_argument("Number of intervals (N) must be positive.");
    } else {
        return (b - a) / N;
    }
}

/*
* Midpoint Rule: rule of approximation
* @param f: function to approximate
* @params a,b: bounds of approximation
* @returns the approximation made by the sum
*/
double Integration::midpointRule(std::function<double(double)> f, double a, double b, int N) {
    
    if (N <= 0) {
        throw std::invalid_argument("Number of intervals (N) must be positive.");
    }
    if (a >= b) {
        throw std::invalid_argument("Upper limit (b) must be greather than lower limit (a).");
    }
    if (!f) {
        throw std::invalid_argument("Function cannot be null!");
    }

    double h = stepSize(a, b, N); // Step size
    double sum = 0.0;
    
    for (int i = 0; i < N; ++i) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }
    
    return h * sum;
}

/*
* Trapezoidal Rule: rule of approximation
* @param f: function to approximate
* @params a,b: bounds of approximation
* @returns the approximation made by the sum
*/
double Integration::trapezoidalRule(std::function<double(double)> f, double a, double b, int N) {
    
    if (N <= 0) {
        throw std::invalid_argument("Number of intervals (N) must be positive.");
    }
    if (a >= b) {
        throw std::invalid_argument("Upper limit (b) must be greather than lower limit (a).");
    }
    if (!f) {
        throw std::invalid_argument("Function cannot be null!");
    }
    
    double h = stepSize(a, b, N); 
    double sum = 0.5 * (f(a) + f(b)); 
    
    for (int i = 1; i < N; ++i) {
        double x = a + i * h;
        sum += f(x);
    }
    
    return h * sum;
}

/*
* Simpson's Rule: rule of approximation
* @param f: function to approximate
* @params a,b: bounds of approximation
* @throws invalid_argument exception: if N is odd (Simpson rule)
* @returns the approximation made by the sum
*/
double Integration::simpsonsRule(std::function<double(double)> f, double a, double b, int N) {
    
    if (N % 2 != 0) {
        throw std::invalid_argument("N must be even for Simpson's rule.");
    } 
    if (N <= 0) {
        throw std::invalid_argument("Number of intervals (N) must be positive.");
    }
    if (a >= b) {
        throw std::invalid_argument("Upper limit (b) must be greather than lower limit (a).");
    }
    if (!f) {
        throw std::invalid_argument("Function cannot be null!");
    }

    double h = stepSize(a, b, N); 
    double sum = f(a) + f(b); 
    
    for (int i = 1; i < N; ++i) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x); 
        } else {
            sum += 4 * f(x); 
        }
    }
    
    return (h / 3) * sum;
}