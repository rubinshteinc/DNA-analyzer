#include "new_parser.h"
#include <exception>
#include <stdexcept>
#include <sstream>

size_t NewParser::countName = 1;

bool NewParser::properCommand(){
    if(m_params.size() < 2 or m_params.size() > 3){
        return false;
    }
    if(m_params.size() == 3) {
        if (m_params[2].find('@') == std::string::npos) {
            throw std::invalid_argument("OOppps! Wrong Name... Did you forgot sign \"@\"??");
        }
    }
    return true;
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