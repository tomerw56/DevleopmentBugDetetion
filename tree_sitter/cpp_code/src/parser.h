#pragma once

#include <string>

class Parser {
public:
    // Parses expressions like: "3 + 4"
    bool parse(const std::string& input, double& lhs, char& op, double& rhs);

private:
    // Helper to trim spaces (BUG: not const-correct)
    std::string trim(std::string& s);
};
