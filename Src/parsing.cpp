#include "parsing.h"
#include <sstream>
#include <iterator>

void Parser::parserInput(std::string &cmd){
    m_params.clear();
    std::istringstream iss(cmd);
    copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         back_inserter(m_params));
}

