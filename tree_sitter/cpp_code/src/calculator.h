#pragma once

#include <string>

class Calculator {
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);   // BUG: no division by zero handling
};
