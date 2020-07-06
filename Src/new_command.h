#ifndef DNA___ANALYZER_NEW_COMMAND_H
#define DNA___ANALYZER_NEW_COMMAND_H

#include "Icommand.h"
#include "meta_data.h"
class New :public ICommand{
public:
    New();
    ~New(){}
    ICommand* create(){New *newCommand = new New(); return newCommand;}
    MetaData* exe(std::string seq, std::string name);


};


#endif //DNA___ANALYZER_NEW_COMMAND_H
