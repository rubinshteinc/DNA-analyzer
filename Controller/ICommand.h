//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_ICOMMAND_H
#define DNA_ANALYZER_ICOMMAND_H

#include <cstddef>
#include "../View/Args.h"



class ICommand{
public:
    virtual ~ICommand(){}
    virtual std::string execute(Args &args) = 0;
};


#endif //DNA_ANALYZER_ICOMMAND_H
