#include "meta_data.h"
#include "dna.h"
size_t MetaData::idCount = 1;

MetaData::MetaData(const std::string &seq, const std::string &name): m_name(name), m_id(idCount++){
    m_seq = new DNASeq(seq);
}
