#ifndef DNA___ANALYZER_FACTORYCOMMAND_H
#define DNA___ANALYZER_FACTORYCOMMAND_H
#include "Icommand.h"
#include "New/new_command.h"
#include "Load/load_command.h"

class Parser;

class FactoryCLI{
public:
    static ICommand* managementCLI(Parser *parser);
};
#endif //DNA___ANALYZER_FACTORYCOMMAND_H
