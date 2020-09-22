//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_NEW_H
#define DNA_ANALYZER_NEW_H

#include <cstddef>
#include "../ICommand.h"
#include "../../Smart Pointers/Shared Ptr/shared_ptr.h"
#include "../../Model/MetaData.h"


class NewCommand : public ICommand{
public:
    ~NewCommand(){}
    size_t execute(Args &args);

private:
    static size_t _nameCount;
    static std::string basicName;
    void extractName(Args &args);
    SharedPtr<MetaData> createDNA(const std::string& DNAseq, const std::string &name) const;

};



#endif //DNA_ANALYZER_NEW_H
