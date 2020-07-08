#ifndef DNA___ANALYZER_ICOMMAND_H
#define DNA___ANALYZER_ICOMMAND_H

#include <cstdlib>
class Parser;

class ICommand{
public:
    virtual ~ICommand(){}
    virtual size_t exe(Parser *parser) = 0;
};


#endif //DNA___ANALYZER_ICOMMAND_H
