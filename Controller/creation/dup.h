//
// Created by a on 9/22/20.
//

#ifndef DNA_ANALYZER_DUP_H
#define DNA_ANALYZER_DUP_H

#include "../ICommand.h"
#include "../../Model/MetaData.h"

class DupCommand : public ICommand{
public:
    ~DupCommand(){}

    std::string execute(Args &args);

private:
    static size_t _nameCount;
    static std::string basicName;
    void extractName(Args &args);
    void extractID(Args &args);
    MetaData* createDNA(const std::string& DNAseq, const std::string &name) const;
};


#endif //DNA_ANALYZER_DUP_H
