#include "parsing.h"
#include <sstream>
#include <iterator>
#include <vector>

std::vector<std::string> Parsing::parserInput(std::string input){
    std::vector<std::string> params;
    std::istringstream iss(input);
    copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         back_inserter(params));
    return params;

}