#ifndef DNA___ANALYZER_LOAD_PARSER_H
#define DNA___ANALYZER_LOAD_PARSER_H
#include "../../parsing.h"

class LoadParser :public Parser{
public:
    bool properCommand();
    void prepareCommand();

private:
    static size_t countName;
};
#endif //DNA___ANALYZER_LOAD_PARSER_H
