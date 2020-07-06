#include "new_command.h"
#include "parsing.h"
New::New(){
    NewParser::properCommand();
    NewParser::prepareCommand();
}


MetaData* New::exe(std::string seq, std::string name = NULL) {
    MetaData *item = new MetaData(seq, name);
    return item;
}

