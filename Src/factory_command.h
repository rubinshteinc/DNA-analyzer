#ifndef DNA___ANALYZER_FACTORYCOMMAND_H
#define DNA___ANALYZER_FACTORYCOMMAND_H
#include "Icommand.h"
#include "string"
#include "new_command.h"
class FactoryCLI{
public:
    ICommand* managementCLI(std::string command);
};
#endif //DNA___ANALYZER_FACTORYCOMMAND_H
