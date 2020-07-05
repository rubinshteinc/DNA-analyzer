#ifndef DNA___ANALYZER_ICOMMAND_H
#define DNA___ANALYZER_ICOMMAND_H
#include "meta_data.h"
class ICommand{
public:
    virtual ~ICommand(){}
    virtual ICommand* create() = 0;
    virtual MetaData* exe(std::string seq, std::string name) = 0;
};


#endif //DNA___ANALYZER_ICOMMAND_H
