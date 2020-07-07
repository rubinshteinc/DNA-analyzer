#include "factory_command.h"


ICommand* FactoryCLI::managementCLI(Parser &parser) {
    ICommand *pICommand = NULL;
    if("new" == parser.getCommand()){
        pICommand = new New(parser);
    }
    return pICommand;
}
