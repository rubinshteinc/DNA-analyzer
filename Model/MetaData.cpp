//
// Created by a on 9/16/20.
//

#include <iostream>
#include "MetaData.h"
#include "DNA_sequence.h"
size_t MetaData::_idCount = 0;


MetaData::MetaData(const std::string &seq, const std::string &name):_seq(new DNASeq(seq)), _name(name), _id(++_idCount), _status('o'){

}

MetaData::~MetaData(){
    delete _seq;
}

std::string MetaData::getSeqAsStr() const{

    return getSeq() -> getSequence();
}

bool MetaData::isLongSeq() const{
    return getSeq() -> tooLongSeq();
}

std::string MetaData::partOfSeq() const{

    std::ostringstream res;
    res << getSeq()->slice(0, 32).getSequence() << "..." << getSeq()->slice(getSeq()->getLength() - 3, getSeq()->getLength()).getSequence();

    return res.str();
}
