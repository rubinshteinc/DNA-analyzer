//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_COMMAND_FACTORY_H
#define DNA_ANALYZER_COMMAND_FACTORY_H

#include <map>
#include <string>
#include "../Controller/ICommand.h"

class CommandCollection{
public:
    static CommandCollection* & getCommandsInstance();
    ICommand* getCommand(const std::string &cmd)const;

private:
    CommandCollection();
//    void initializedCommands();
    static CommandCollection* _pObj;

    std::map<std::string, ICommand* > _commands;
};

inline ICommand* CommandCollection::getCommand(const std::string &cmd)const{

    return _commands.find(cmd) -> second;
}



#endif //DNA_ANALYZER_COMMAND_FACTORY_H
