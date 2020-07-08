#ifndef DNA___ANALYZER_FACTORYCOMMAND_H
#define DNA___ANALYZER_FACTORYCOMMAND_H
#include "Icommand.h"
#include "new_command.h"

class Parser;

class FactoryCLI{
public:
    static ICommand* managementCLI(Parser *parser);
};
#endif //DNA___ANALYZER_FACTORYCOMMAND_H
