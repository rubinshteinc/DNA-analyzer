#include "meta_data.h"
#include <iterator>
size_t MetaData::idCount = 1;

MetaData::MetaData(const std::string &seq, const std::string &name):m_seq(new DNASeq(seq)), m_name(name), m_id(idCount){
    ++idCount;
}


MetaData::~MetaData(){
    delete m_seq;
//    std::cout << "Dtor MetaData..." << std::endl;
    m_seq = NULL;
}



HashTableData::~HashTableData(){
    for (size_t i = 0; i < m_HashTableId.size(); ++i){
        delete[] m_HashTableId[i];
    }
}


void HashTableData::print(size_t id){

    std::cout << "[" << id << "] ";
    std::cout << m_HashTableId[id]->m_name << ": ";
    std::cout << m_HashTableId[id]->m_seq->getSeq() << std::endl;
}
