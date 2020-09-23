//
// Created by a on 9/21/20.
//

#include "load.h"
#include <sstream>
#include <fstream>
#include "../../View/Args.h"
#include "../../Model/MetaData.h"
#include "../../Model/DNACollection.h"

void LoadCommand::extractName(Args &args){
    std::stringstream ss;

    if(args.size() == 2){
        ss << args.getFilename().substr(0, args.getFilename().find('.'));

    }

    else if (args.getName()[0] != '@'){
        throw std::invalid_argument("Wrong Name... Did you forgot sign \"@\"??");
    }

    else{
        ss << args.getName().substr(1, args.getName().length());
    }

    args.pushName(NAME, ss.str());
}


MetaData* LoadCommand::createDNA(const std::string& DNAseq, const std::string &name) const{

    return new MetaData(DNAseq, name);
}


void LoadCommand::readDNAFromFile(std::string &seq, const std::string &filename) const{
    std::ifstream file(filename.c_str());

    if (file.is_open()){
        getline(file, seq);
        file.close();
    }

    else{
        throw std::ios_base::failure("Error in opening the file");
    }
}


std::string LoadCommand::execute(Args &args){

    std::string result;

    if(args.size() == 1){
        throw std::invalid_argument("Missing arguments");
    }
    std::string sequence;
    readDNAFromFile(sequence, args.getFilename());
    extractName(args);
    MetaData *newDNA = createDNA(sequence, args.getName());
    DNACollection::addDNA(newDNA);


    result = '[' + newDNA -> getIDAsStr() + "] " + newDNA -> getName() + ": ";

    if(newDNA -> isLongSeq()){
        result += newDNA -> partOfSeq();
    }

    else{
        result += newDNA -> getSeqAsStr();
    }

    return result;
}




