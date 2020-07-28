#include <iosfwd>
#include <cstdint>
#include <tuple>

std::string parseNumber(const std::string& numberString);
bool validatePhone(const std::string& numberString);
std::vector<std::tuple<std::string, bool>> ambiguities(const std::string& numberString);
