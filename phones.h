#include <cstdint>
#include <tuple>
#include <string>
#include <vector>

std::string parseNumber(const std::string& numberString);
bool validatePhone(const std::string& numberString);
std::vector<std::tuple<std::string, bool>> ambiguities(const std::string& numberString);
