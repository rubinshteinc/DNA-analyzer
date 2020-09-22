//
// Created by a on 9/16/20.
//
#include <stdexcept>
#include "DNACollection.h"

std::map<std::string, size_t> DNACollection::_nameToId;
std::map<size_t , SharedPtr<MetaData> > DNACollection::_idToData;

void DNACollection::addDNA(SharedPtr<MetaData> &DNA){
        std::pair<std::map<std::string, size_t>::iterator,bool> it = _nameToId.insert(std::pair<std::string, size_t>(DNA -> getName(), DNA -> getID()));

        if(!it.second) {
            throw std::invalid_argument("Name already exist!, please enter another...");
        }

        _idToData.insert(std::pair<size_t , SharedPtr<MetaData> >(DNA -> getID(), DNA));
}

std::string DNACollection::getNameById(size_t id){
    return _idToData[id] -> getName();
}

DNASeq* DNACollection::getSeqById(size_t id){
    return _idToData[id] -> getSeq();
}

