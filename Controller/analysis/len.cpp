//
// Created by a on 9/22/20.
//

#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include "len.h"
#include "../../Model/DNACollection.h"
#include "../../Model/DNA_sequence.h"


void LenCommand::extractID(Args &args){
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

std::string LenCommand::execute(Args &args){

    std::stringstream result;
    if(args.size() == 1){
        throw std::invalid_argument("Missing arguments");
    }

    extractID(args);
    result << DNACollection::getSeqById(atoi(args.getID().c_str())) -> getLength();

    return result.str();
}
