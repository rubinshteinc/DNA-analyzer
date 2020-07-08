#ifndef DNA___ANALYZER_PARSING_H
#define DNA___ANALYZER_PARSING_H
#include <vector>
#include <string>

class Parser{
public:
    void parserInput(std::string &cmd);
    std::string getCommand()const{ return m_params[0];}
    std::string getSeq()const{ return m_params[1];}
    std::string getName()const{ return m_params[2];}

protected:
    std::vector<std::string> m_params;
};


class NewParser :public Parser{
public:
    bool properCommand();
    void prepareCommand();

private:
    static size_t countName;
};
#endif //DNA___ANALYZER_PARSING_H

