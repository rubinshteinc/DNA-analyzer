//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_DNACOLLECTION_H
#define DNA_ANALYZER_DNACOLLECTION_H

#include <map>
#include <cstddef>
#include "MetaData.h"

class DNACollection{
public:
    static void addDNA(MetaData *DNA);
    static std::string getNameById(size_t id);
    static DNASeq* getSeqById(size_t id);
    static bool isExist(const std::string &name);
    static bool availableID(size_t id);


private:

    static std::map<std::string, size_t> _nameToId;
    static std::map<size_t, MetaData*> _idToData;
};




#endif //DNA_ANALYZER_DNACOLLECTION_H
