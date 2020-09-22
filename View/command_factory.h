//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_COMMAND_FACTORY_H
#define DNA_ANALYZER_COMMAND_FACTORY_H

#include <map>
#include <string>
#include "../Smart Pointers/Shared Ptr/shared_ptr.h"
#include "../Controller/ICommand.h"

class CommandCollection{
public:
    static const SharedPtr<CommandCollection>& getCommandsInstance();
    const SharedPtr<ICommand>& getCommand(const std::string &cmd)const;

private:
    CommandCollection();
//    void initializedCommands();
    static SharedPtr<CommandCollection> _pObj;

    std::map<std::string, SharedPtr<ICommand> > _commands;
};

inline const SharedPtr<ICommand>& CommandCollection::getCommand(const std::string &cmd)const{

    return _commands.find(cmd) -> second;
}



#endif //DNA_ANALYZER_COMMAND_FACTORY_H
