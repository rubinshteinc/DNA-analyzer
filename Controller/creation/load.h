//
// Created by a on 9/21/20.
//

#ifndef DNA_ANALYZER_LOAD_H
#define DNA_ANALYZER_LOAD_H

#include "../ICommand.h"
#include "../../Model/MetaData.h"

class LoadCommand : public ICommand{
public:
    ~LoadCommand(){}

    std::string execute(Args &args);

private:
    void extractName(Args &args);
    MetaData* createDNA(const std::string& DNAseq, const std::string &name) const;

    void readDNAFromFile(std::string &sequence, const std::string &filename) const;
};


#endif //DNA_ANALYZER_LOAD_H
