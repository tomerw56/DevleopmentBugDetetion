// fragile_api_lifetime.cpp
#include <string>

const char* GetServiceName()
{
    static std::string name = "PaymentService";
    return name.c_str();   //Fragile: exposes internal buffer
}
