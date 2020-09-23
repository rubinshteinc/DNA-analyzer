//
// Created by a on 9/22/20.
//

#include "dup.h"

#include <sstream>
#include <cstdlib>
#include "../../View/Args.h"
#include "../../Model/MetaData.h"
#include "../../Model/DNACollection.h"
#include "../../Model/DNA_sequence.h"

void DupCommand::extractName(Args &args){

    size_t nameCount = 0;
    std::stringstream copiedName;

    if(args.size() == 2){
        copiedName << DNACollection::getNameById(atoi(args.getID().c_str())) << '_' << ++nameCount;
        while(DNACollection::isExist(copiedName.str())){

            copiedName.seekp(-1, std::ios_base::end);
            copiedName << ++nameCount;
        }
    }

    else if (args.getName()[0] != '@'){
        throw std::invalid_argument("Wrong Name... Did you forgot sign \"@\"??");
    }

    else{
        copiedName << args.getName().substr(1, args.getName().length());
    }

    args.pushName(NAME, copiedName.str());
}


void DupCommand::extractID(Args &args){
    std::stringstream ss;

    if (args.getID()[0] != '#'){
        throw std::invalid_argument("Wrong ID... Did you forgot sign \"#\"??");
    }

    else{
        ss << args.getID().substr(1, args.getID().length());
    }

    args.pushID(ss.str());
    if(!DNACollection::availableID(atoi(args.getID().c_str()))){
        throw std::invalid_argument("Invalid ID.");
    }

}


MetaData* DupCommand::createDNA(const std::string& DNAseq, const std::string &name) const{

    return new MetaData(DNAseq, name);
}


std::string DupCommand::execute(Args &args){

    std::string result;
    if(args.size() == 1){
        throw std::invalid_argument("Missing arguments");
    }

    extractID(args);
    extractName(args);
    std::string seq = DNACollection::getSeqById(atoi(args.getID().c_str())) -> getSequence();
    MetaData *newDNA = createDNA(seq, args.getName());
    DNACollection::addDNA(newDNA);

    result = '[' + newDNA -> getIDAsStr() + "] " + newDNA -> getName() + ": " + newDNA -> getSeqAsStr();

    return result;
}


