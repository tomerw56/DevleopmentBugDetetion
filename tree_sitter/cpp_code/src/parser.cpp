#include "parser.h"
#include <sstream>

// BUG: trim should take const std::string& but mutates copy
std::string Parser::trim(std::string& s) {
    size_t start = s.find_first_not_of(" ");
    size_t end = s.find_last_not_of(" ");

    if (start == std::string::npos) {
        return "";
    }
    return s.substr(start, end - start + 1);
}

bool Parser::parse(const std::string& input, double& lhs, char& op, double& rhs) {
    std::string local = input;
    local = trim(local);

    std::istringstream iss(local);

    // BUG: no validation of format or operator
    iss >> lhs >> op >> rhs;

    // BUG: ignoring stream state, always returns true
    return true;
}

