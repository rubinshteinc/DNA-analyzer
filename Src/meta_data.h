#ifndef DNA___ANALYZER_META_DATA_H
#define DNA___ANALYZER_META_DATA_H

#include "dna.h"

class MetaData{
public:
    MetaData(std::string seq, std::string name);
private:
    static size_t idCount;
    DNASeq *m_seq;
    std::string m_name;
    size_t  m_id;
};
#endif //DNA___ANALYZER_META_DATA_H
