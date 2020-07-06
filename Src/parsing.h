#ifndef DNA___ANALYZER_PARSING_H
#define DNA___ANALYZER_PARSING_H
#include <vector>
#include <string>

class Parser{
public:
    void parserInput(std::string input);
    std::string getCommand()const{ return m_params[0];}

protected:
    std::vector<std::string> m_params;
};

class NewParser :public Parser {
public:
    static bool properCommand();
    static void prepareCommand();

private:
    static size_t countName;
};
#endif //DNA___ANALYZER_PARSING_H

