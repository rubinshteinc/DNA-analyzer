#include "new_command.h"
#include "../parsing.h"
#include "../app.h"


New::New(Parser *parser){
    NewParser *p = static_cast<NewParser*>(parser);
    if(p -> properCommand()){
        p -> prepareCommand();
    }
    else{
        throw ; //complete specific command
    }
}


size_t New::exe(Parser *parser) {
    MetaData *item = new MetaData(parser -> getSeq(), parser -> getName());
    App::m_data.addDNA(item);
    return item->m_id;
}

