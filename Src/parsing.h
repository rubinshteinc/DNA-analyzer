#ifndef DNA___ANALYZER_PARSING_H
#define DNA___ANALYZER_PARSING_H
#include <vector>
#include <string>

class Parser{
public:
    void parserInput(std::string &cmd);
    std::string getCommand()const{ return m_params[0];}
    std::string getDetails()const{ return m_params[1];}
    std::string getName()const{ return m_params[2];}

protected:
    std::vector<std::string> m_params;
};



#endif //DNA___ANALYZER_PARSING_H

