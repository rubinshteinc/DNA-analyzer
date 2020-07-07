#ifndef DNA___ANALYZER_NEW_COMMAND_H
#define DNA___ANALYZER_NEW_COMMAND_H
#include "parsing.h"
#include "Icommand.h"
#include "meta_data.h"
class New :public ICommand{
public:
    New(Parser parser);
    ~New(){}
//    ICommand* create(){New *newCommand = new New(); return newCommand;}
    MetaData* exe(Parser &parser);
};


#endif //DNA___ANALYZER_NEW_COMMAND_H
