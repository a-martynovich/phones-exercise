#include "phones.h"

#include <iostream>
#include <sstream>
#include <cmath>
#include <array>
#include <vector>
#include <tuple>


const size_t SHORT_LENGTH = 10,
             LONG_LENGTH = 14;
const std::array<std::string, 2> SHORT_PREFIXES { "2", "69"},
                                 LONG_PREFIXES {"00302", "003069"};

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
    if(phone.length() == SHORT_LENGTH)
        for(auto&& s: SHORT_PREFIXES) {
            if(phone.substr(0, s.length()) == s)
                return true;
        }
    else if(phone.length() == LONG_LENGTH)
        for(auto&& s: LONG_PREFIXES) {
            if(phone.substr(0, s.length()) == s)
                return true;
        }
    
    return false;
}

void append(const std::string& s, std::vector<std::string>& in, std::vector<std::string>& out) {
    if(!in.size()) {
        out.push_back(s);
        std::cout << "append: " << s << std::endl;
        return;
    }
    
    for(auto& v: in) {
        out.push_back(v + s);
        std::cout << "append: " << v+s << std::endl;
    }
}

void gen(const std::string& spawn, std::vector<std::string>& in, std::vector<std::string>& out) {
    std::string res;
    std::cout << "spawn " << spawn << std::endl;
    int N = spawn.length();
    for(int i=0; i<N; i++) {
        std::string s;
        s.resize(N, '0');
        for(int k=0; k<i+1; k++)
            s[k] = spawn[k];
        if(spawn[i+1] == '0')
            continue;
        std::cout << "## " << s << std::endl;
        res = s;
        
        for(int j=i+1; j<N; j++) {
            std::string s;
            s.resize(N-j, '0');
            if(spawn[j] == '0')
                break;
            s[0] = spawn[j];
            std::cout << "# " << s << std::endl;
            res += s;
        }
        append(res, in, out);
    }
    // abcd: a000 b00 c0 d, ab00 c0 d, abc0 d, abcd
    // abc: a00 b0 c, ab0 c, abc
    // ab: a0 b, ab
    in = out;
    out.clear();
}

std::vector<std::tuple<std::string, bool>> ambiguities(const std::string& numberString) {
    std::istringstream iss(numberString);
    std::string n, merged;
    int merged_zeros = 0;
    std::vector<std::string> result, temp;
    std::vector<std::tuple<std::string, bool>> res;
    
    while(iss >> n) {
        char* p;
        strtol(n.c_str(), &p, 10);
        if(*p != 0)
            return res;
        
            
        int zeros = 0;
        if(n != "0")
        for(auto i = n.crbegin(); i != n.crend(); ++i) {
            if(*i == '0')
                zeros++;
            else
                break;
        }
                
        if(merged.length()) {
            if(merged_zeros >= n.length()) {
                merged.replace(merged.length()-n.length(), std::string::npos, n);
                bool isLast = (iss.tellg() == -1);
                if(!zeros || isLast) {
                    gen(merged, result, temp);
                } else {
                }
            } else {
                std::cout << n << " " << merged << std::endl;
                gen(merged, result, temp);
                gen(n, result, temp);
                if(zeros)
                    merged = n;
            }
        } else if(zeros && n != "10") {
            merged = n;
        } else {
            gen(n, result, temp);
        }
        
        if(zeros == 0) {
            merged = "";
            merged_zeros = 0;
        } else {
            merged_zeros = zeros;
        }
    }
    
    for(auto&& s: result) {
        res.push_back({s, validatePhone(s)});
    }
    return res;
}

int main1(int argc, char** argv) {
    std::cout << parseNumber("123 456") << std::endl;
    return 1;
}
