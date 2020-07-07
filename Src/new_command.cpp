#include "new_command.h"
#include "parsing.h"
New::New(Parser parser){
    NewParser *p = reinterpret_cast<NewParser*>(&parser);
//    p -> properCommand();
//    p -> prepareCommand();
}


MetaData* New::exe(Parser &parser) {
    MetaData *item = new MetaData(parser.getSeq(), parser.getName());
    return item;
}

