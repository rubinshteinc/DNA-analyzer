#include "load_parser.h"
#include <stdexcept>
#include <sstream>


bool LoadParser::properCommand(){
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

void LoadParser::prepareCommand(){
    if(m_params.size() == 2) {
        std::ostringstream defaultName;
        defaultName << (m_params[1].substr(0, m_params[1].find(".")));
        m_params.push_back(defaultName.str());
    }
    else{
        m_params[2] = m_params[2].substr(1);
    }
}