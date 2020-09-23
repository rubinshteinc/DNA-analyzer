//
// Created by a on 9/22/20.
//

#ifndef DNA_ANALYZER_LEN_H
#define DNA_ANALYZER_LEN_H

#include "../ICommand.h"

class LenCommand : public ICommand{
public:
    ~LenCommand(){}
    std::string execute(Args &args);
    void extractID(Args &args);
};




#endif //DNA_ANALYZER_LEN_H
