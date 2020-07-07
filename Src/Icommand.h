#ifndef DNA___ANALYZER_ICOMMAND_H
#define DNA___ANALYZER_ICOMMAND_H
#include "meta_data.h"
#include "parsing.h"
class ICommand{
public:
    virtual ~ICommand(){}
//    virtual ICommand* create() = 0;
    virtual MetaData* exe(Parser &parser) = 0;
};


#endif //DNA___ANALYZER_ICOMMAND_H
