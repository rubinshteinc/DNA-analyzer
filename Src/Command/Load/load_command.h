#ifndef DNA___ANALYZER_LOAD_COMMAND_H
#define DNA___ANALYZER_LOAD_COMMAND_H

#include "../Icommand.h"
class Parser;

class Load: public ICommand{
public:
    Load(Parser *parser);
    virtual ~Load(){}
    virtual size_t exe(Parser *parser);
};


#endif //DNA___ANALYZER_LOAD_COMMAND_H
