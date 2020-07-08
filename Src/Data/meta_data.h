#ifndef DNA___ANALYZER_META_DATA_H
#define DNA___ANALYZER_META_DATA_H
#include "dna.h"
#include <map>


class MetaData{
public:
    MetaData(const std::string &seq, const std::string &name);
    ~MetaData();
    static size_t idCount;
    DNASeq *m_seq;
    std::string m_name;
    size_t m_id;
    char m_status;
};

class HashTableData{
public:

    ~HashTableData();
    //    MetaData* getDNAByName(std::string &name){ return m_HashTableId[id];}
    void addDNA(MetaData* DNA){m_HashTableId.insert(PairHashTableId(DNA->m_id, DNA));
                                m_hashTableName.insert(PairHashTableName(DNA ->m_name, DNA -> m_id));}
    MetaData* getDNAById(size_t id){ return m_HashTableId[id];}

    void print(size_t id);

private:
    typedef std::map<size_t , MetaData*> HashTableId;
    typedef std::pair<size_t, MetaData*> PairHashTableId;
    typedef std::map<std::string , size_t> HashTableName;
    typedef std::pair<std::string, size_t> PairHashTableName;


    HashTableId m_HashTableId;
    HashTableName m_hashTableName;
};
#endif //DNA___ANALYZER_META_DATA_H
