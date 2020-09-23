//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_TERMINAL_H
#define DNA_ANALYZER_TERMINAL_H

#include <string>
#include "command_factory.h"


class Terminal{
public:
    Terminal();
    void run();
    void command();
    void printResult(const std::string &res) const;
    bool isEmpty(const std::string &str) const;

private:
    static std::string _prompt;
    CommandCollection *_pFactory;
};

inline bool Terminal::isEmpty(const std::string &str) const{
    return str.empty();
}

#endif //DNA_ANALYZER_TERMINAL_H
