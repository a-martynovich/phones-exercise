#include <iosfwd>
#include <cstdint>

std::string parseNumber(const std::string& numberString);
bool validatePhone(const std::string& numberString);
std::vector<std::string> ambiguities(const std::string& numberString);
