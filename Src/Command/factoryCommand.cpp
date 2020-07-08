#include "factory_command.h"
#include "../parsing.h"
#include <stdexcept>

ICommand* FactoryCLI::managementCLI(Parser *parser) {
    try{
        if("new" == parser -> getCommand()){
            return new New(parser);
        }
    }
    catch (std::invalid_argument&e){
        throw ;}
    throw std::invalid_argument("OOppps! Wrong command");
}
