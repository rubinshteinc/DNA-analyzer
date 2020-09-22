//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_TERMINAL_H
#define DNA_ANALYZER_TERMINAL_H

#include <string>
#include "../Smart Pointers/Shared Ptr/shared_ptr.h"
#include "command_factory.h"


class Terminal{
public:
    Terminal();
    void run();
    void command();
    void print(size_t DNAID) const;

private:
    static std::string _prompt;
    SharedPtr<CommandCollection> _pFactory;
};


#endif //DNA_ANALYZER_TERMINAL_H
