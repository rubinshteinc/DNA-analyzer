#ifndef DNA___ANALYZER_SAVE_PARSER_H
#define DNA___ANALYZER_SAVE_PARSER_H

#include "../parsing.h"

class SaveParser : public Parser{
public:
    bool properCommand();
    void prepareCommand();

private:
    static std::string FileSuffix;
};

#endif //DNA___ANALYZER_SAVE_PARSER_H
