//
// Created by a on 9/16/20.
//

#include "command_factory.h"
#include "../Controller/creation/new.h"


//std::map<std::string, SharedPtr<ICommand> > CommandCollection::_commands = initializedCommands();
SharedPtr<CommandCollection> CommandCollection::_pObj;

const SharedPtr<CommandCollection>& CommandCollection::getCommandsInstance(){
    if (!_pObj){
        _pObj = SharedPtr<CommandCollection>(new CommandCollection);
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

    SharedPtr<NewCommand> cnew(new NewCommand);
    _commands.insert(std::make_pair("new", cnew));
}


//SharedPtr<ICommand> CommandCollection::getCommand(const std::string &cmd)const{
//
//    return SharedPtr<ICommand>(getCommandsInstance()->_commands.find(cmd) -> second);
//}