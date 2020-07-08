#include "new_command.h"
#include "../parsing.h"
#include "../app.h"


New::New(Parser *parser){
    NewParser *p = static_cast<NewParser*>(parser);
    try{
        if(p -> properCommand()){
            p -> prepareCommand();
        }
    }
    catch (const std::invalid_argument &e){
       throw;
    }
}


size_t New::exe(Parser *parser) {
    MetaData *item = new MetaData(parser -> getSeq(), parser -> getName());
    App::m_data.addDNA(item);
    return item->m_id;
}

