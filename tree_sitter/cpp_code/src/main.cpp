#include <iostream>
#include "calculator.h"
#include "parser.h"

int main() {
    Calculator calc;
    Parser parser;

    std::cout << "Enter expression (e.g. 3 + 4): ";

    std::string input;
    std::getline(std::cin, input);

    double lhs = 0.0;
    double rhs = 0.0;
    char op = 0;

    if (!parser.parse(input, lhs, op, rhs)) {
        std::cerr << "Failed to parse expression\n";
        return 1;
    }

    double result = 0.0;

    switch (op) {
    case '+':
        result = calc.add(lhs, rhs);
        break;
    case '-':
        result = calc.subtract(lhs, rhs);
        break;
    case '*':
        result = calc.multiply(lhs, rhs);
        break;
    case '/':
        result = calc.divide(lhs, rhs);   // BUG: division by zero crashes/inf
        break;
    default:
        std::cerr << "Unknown operator: " << op << "\n";
        return 1;
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}
