//
// Created by a on 9/16/20.
//

#include <iostream>
#include <sstream>
#include "new.h"
#include "../../View/Args.h"
#include "../../Model/MetaData.h"
#include "../../Model/DNACollection.h"

size_t NewCommand::_nameCount = 0;
std::string NewCommand::basicName = "seq";

void NewCommand::extractName(Args &args){
    std::stringstream ss;

    if(args.size() == 2){
        ss << basicName << (++_nameCount);

    }

    else if (args.getName()[0] != '@'){
        throw std::invalid_argument("Wrong Name... Did you forgot sign \"@\"??");
    }

    else{
        ss << args.getName().substr(1, args.getName().length());
    }

    args.pushName(NAME, ss.str());
}


SharedPtr<MetaData> NewCommand::createDNA(const std::string& DNAseq, const std::string &name) const{
    try{
        return SharedPtr<MetaData> (new MetaData(DNAseq, name));
    }

    catch (std::invalid_argument &exp){
        --_nameCount;
        throw;
    }
}


size_t NewCommand::execute(Args &args){

    if(args.size() == 1){
        throw std::invalid_argument("Missing arguments");
    }

    //TODO לשנות את השימוש ב DNACOLLECTION וב- COMMANDCOLLECTION לשימוש ב SINGELTON
    extractName(args);
    SharedPtr<MetaData> newDNA = createDNA(args.getSeq(), args.getName());
    DNACollection::addDNA(newDNA);

    return newDNA -> getID();
}


