#ifndef DNA___ANALYZER_META_DATA_H
#define DNA___ANALYZER_META_DATA_H

#include "dna.h"
#include <map>
class MetaData{
public:
    MetaData(const std::string &seq, const std::string &name);
    static size_t idCount;
    DNASeq *m_seq;
    std::string m_name;
    size_t m_id;
};

class HashTableData{
public:
    void insretData(MetaData &p){m_data.insert(std::pair<size_t, MetaData>(p.m_id , p));}
private:
    std::map<size_t, MetaData*> m_data;
};
#endif //DNA___ANALYZER_META_DATA_H
