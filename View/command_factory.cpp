//
// Created by a on 9/16/20.
//

#include "command_factory.h"
#include "../Controller/creation/new.h"
#include "../Controller/creation/load.h"
#include "../Controller/creation/dup.h"


//std::map<std::string, SharedPtr<ICommand> > CommandCollection::_commands = initializedCommands();
CommandCollection* CommandCollection::_pObj;

CommandCollection* & CommandCollection::getCommandsInstance(){
    if (!_pObj){
        _pObj = new CommandCollection;
    }

    return _pObj;
}


//void CommandCollection::initializedCommands() {
//    SharedPtr<NewCommand> cnew(new NewCommand);
//    getCommandsInstance() -> _commands.insert(std::make_pair("new", cnew));
//}

//std::map<std::string, SharedPtr<ICommand> > CommandCollection::initializedCommands() {
//    std::map<std::string, SharedPtr<ICommand> > tmp;
//    SharedPtr<NewCommand> cnew(new NewCommand);
//    tmp.insert(std::make_pair("new", cnew));
//    return tmp;
//}


CommandCollection::CommandCollection() {

    NewCommand *cnew(new NewCommand);
    _commands.insert(std::make_pair("new", cnew));

    LoadCommand *cload(new LoadCommand);
    _commands.insert(std::make_pair("load", cload));

    DupCommand *cdup(new DupCommand);
    _commands.insert(std::make_pair("dup", cdup));
}


//SharedPtr<ICommand> CommandCollection::getCommand(const std::string &cmd)const{
//
//    return SharedPtr<ICommand>(getCommandsInstance()->_commands.find(cmd) -> second);
//}