// missing_error_checks.cpp
#include <cstdio>
#include <string>

void WriteFile(const std::string& path, const std::string& data)
{
    FILE* f = fopen(path.c_str(), "w");   // not checked
    fprintf(f, "%s\n", data.c_str());     //return ignored
    fclose(f);
}
