#include "meta_data.h"

size_t MetaData::idCount = 1;
MetaData::MetaData(const std::string &seq, const std::string &name): m_name(name), m_id(idCount), m_seq(new DNASeq(seq)){
    ++idCount;
}

void HashTableData::print(size_t id){

    std::cout << "[" << id << "] ";
    std::cout << m_HashTableId[id]->m_name << ": ";
    std::cout << m_HashTableId[id]->m_seq->getSeq() << std::endl;
}
