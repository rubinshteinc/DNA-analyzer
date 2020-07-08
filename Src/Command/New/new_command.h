#ifndef DNA___ANALYZER_NEW_COMMAND_H
#define DNA___ANALYZER_NEW_COMMAND_H

#include <cstdlib>
#include "../Icommand.h"

class Parser;

class New :public ICommand{
public:
    New(Parser *parser);
    virtual ~New(){}
    virtual size_t exe(Parser *parser);
};


#endif //DNA___ANALYZER_NEW_COMMAND_H
