//
// Created by a on 9/16/20.
//


#include <iostream>
#include "terminal.h"
#include "../Controller/ICommand.h"
#include "command_factory.h"
#include "Args.h"
#include "../Model/DNACollection.h"
#include "../Model/DNA_sequence.h"

std::string Terminal::_prompt = "> cmd >>>";

Terminal::Terminal():_pFactory(CommandCollection::getCommandsInstance()){

}


void Terminal::run() {

    while(1){
        try {
            std::cout << _prompt;
            command();
        }
        catch (std::exception &exp){
            std::cout << exp.what() << std::endl;
        }
    }

}

void Terminal::command() {
    std::string cmd;
    getline(std::cin , cmd);
    Args args(cmd);
    size_t DNAIDResult;
    
    SharedPtr<ICommand> command = _pFactory -> getCommand(args.getCommandName());

    if(command){
        DNAIDResult = command -> execute(args);
        print(DNAIDResult);
    }

    else{
        std::cout << "OOppps! Wrong command" << std::endl;
    }



}

void Terminal::print(size_t DNAID) const{
    std::cout << "[" << DNAID << "] ";
    std::cout << DNACollection::getNameById(DNAID) << ": ";

    std::cout << DNACollection::getSeqById(DNAID) -> getSequence() << std::endl;
}