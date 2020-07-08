#include "factory_command.h"
#include "../parsing.h"

ICommand* FactoryCLI::managementCLI(Parser *parser) {
    if("new" == parser -> getCommand()){
        return new New(parser);
    }
    return NULL;
}
