/* 
* Header file for Integration.hpp
* Declaration of a class containing methods and constructor for approximating integrals using composite numerical integration formulas.
* contains: public constructor, method to approx with midpoint rule, trapezoidal rule, Simpson rule.
*/

#ifndef INTEGRATION_HPP__
#define INTEGRATION_HPP__

#include <vector>
#include <functional>

class Integration {

    public :

        // Public constructor
        Integration();

        // Numerical integratrion modules:
        // Midpoint rule
        double midpointRule(std::function<double(double)> f, double a, double b, int N);

        // Trapezoidal rule
        double trapezoidalRule(std::function<double(double)> f, double a, double b, int N);

        // Simpson rule
        double simpsonsRule(std::function<double(double)> f, double a, double b, int N);

    private:

        //helper function to calculate step size
        double stepSize(double a, double b, int N);

};

#endif // INTEGRATION_HPP__