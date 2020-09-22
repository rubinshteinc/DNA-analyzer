//
// Created by a on 9/16/20.
//

#include "MetaData.h"
#include "DNA_sequence.h"
size_t MetaData::_idCount = 0;


MetaData::MetaData(const std::string &seq, const std::string &name):_seq(new DNASeq(seq)), _name(name), _id(++_idCount), _status('o'){

}

MetaData::~MetaData(){
    delete _seq;
}