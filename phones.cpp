#include "phones.h"

#include <iostream>
#include <sstream>
#include <cmath>


std::string parseNumber(const std::string& numberString) {
    std::istringstream iss(numberString);
    std::string n;
    std::string result;
    while(iss >> n) {
        char* p;
        strtol(n.c_str(), &p, 10);
        if(*p != 0)
            return "";
        
        result.append(n);
    }
    return result;
}

bool validatePhone(const std::string& numberString) {
    std::istringstream iss(numberString);
    std::string phone = parseNumber(numberString);
    if(phone.empty())
        return false;
}

int main1(int argc, char** argv) {
    std::cout << parseNumber("123 456") << std::endl;
    return 1;
}
