#include <iostream>
#include <sstream>
#include <cmath>
#include <array>
#include <vector>
#include <tuple>

#include "phones.h"


int usage() {
    std::cout << "Usage: phones <merge|validate|ambiguities> \"number\"" << std::endl << "Make sure to enclose the number in quotes!" << std::endl;
    return 1;
}

int main(int argc, char** argv) {
    if(argc != 3) {
        return usage();
    }
    std::string arg1 = argv[1], arg2 = argv[2];
    if(arg1 == "merge") {
        std::cout << parseNumber(arg2) << std::endl;
        return 0;
    } else if(arg1 == "validate") {
        auto s = parseNumber(arg2);
        auto valid = validatePhone(s)? "VALID": "INVALID";
        std::cout << s << " [phone number: " << valid << "]" << std::endl;
        return 0;
    } else if(arg1 == "ambiguities") {
        auto numbers = ambiguities(arg2);
        for(int i=0; i<numbers.size(); i++) {
            auto& num = numbers[i];
            auto& s = std::get<0>(num);
            auto& isValid = std::get<1>(num);
            auto valid = isValid? "VALID": "INVALID";
            std::cout <<"Interpretation " << i+1 <<": " << s << " [phone number: " << valid << "]" << std::endl;
        }
        return 0;
    }
    return usage();
}

