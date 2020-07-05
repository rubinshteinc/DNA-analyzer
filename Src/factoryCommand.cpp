#include "factory_command.h"


ICommand* FactoryCLI::managementCLI(std::string command) {
    ICommand *icommand = NULL;
    if("new" == command){
        icommand = new New;
    }
    return icommand;
}
