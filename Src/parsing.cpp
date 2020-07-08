#include "parsing.h"
#include <sstream>
#include <iterator>
size_t NewParser::countName = 1;

void Parser::parserInput(std::string &cmd){
    m_params.clear();
    std::istringstream iss(cmd);
    copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         back_inserter(m_params));
}

bool NewParser::properCommand(){
    return !((m_params.size() < 2 or m_params.size() > 3) or (m_params[2].find('@') == std::string::npos));
}

void NewParser::prepareCommand(){
    if(m_params.size() == 2) {
        std::stringstream defaultName;
        defaultName << "seq" << countName;
        m_params.push_back(defaultName.str());
        ++countName;
    }
    else{
        m_params[2] = m_params[2].substr(1);
    }
}