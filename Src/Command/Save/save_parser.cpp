#include "save_parser.h"
#include <exception>
#include <stdexcept>
#include <sstream>

std::string SaveParser::m_fileSuffix = ".rawdna";

bool SaveParser::properCommand(){
    return (m_params.size() < 2 or m_params.size() > 3);

}

void SaveParser::prepareCommand(){
    if(m_params.size() == 1) {
        std::stringstream defaultName;
        defaultName << m_params[1]; <<
        m_params.push_back(defaultName.str());
    }
    else{
        m_params[2] = m_params[2].substr(1);
    }
}