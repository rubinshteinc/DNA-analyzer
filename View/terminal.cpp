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

    if(isEmpty(cmd)){
        return;
    }

    Args args(cmd);
    std::string commandResult;
    
    ICommand *command = _pFactory -> getCommand(args.getCommandName());

    if(command){

        commandResult = command -> execute(args);
        printResult(commandResult);
    }

    else{
        std::cout << "OOppps! Wrong command" << std::endl;
    }



}

void Terminal::printResult(const std::string & res) const{
    std::cout << res << std::endl;
}