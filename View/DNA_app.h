//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_DNA_APP_H
#define DNA_ANALYZER_DNA_APP_H

#include "terminal.h"

class DNAApp{
public:
    void start();

private:
    Terminal _terminal;
};

inline void DNAApp::start(){
    _terminal.run();
}
#endif //DNA_ANALYZER_DNA_APP_H
