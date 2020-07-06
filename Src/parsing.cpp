#include "parsing.h"
#include <sstream>
#include <iterator>
#include <vector>
size_t NewParser::countName = 1;

void Parser::parserInput(std::string input){
    std::vector<std::string> params;
    std::istringstream iss(input);
    copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         back_inserter(params));

}
bool NewParser::properCommand(){
    if(m_params.size() < 2 or m_params.size() > 3){
        throw ; //complete specific exception
    }

}
void NewParser::prepareCommand(){
    if(m_params.size() == 2) {
        std::stringstream defaultName;
        defaultName << "seq_" << countName;
        m_params.push_back(defaultName.str());
        ++countName;
    }
    else{
        m_params[2] = m_params[2].substr();
    }
}