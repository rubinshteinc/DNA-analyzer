#include "load_command.h"
#include "../../I_O/input_data.h"
#include "../../app.h"
#include "../../parsing.h"
#include "load_parser.h"

Load::Load(Parser *parser){
    LoadParser *p = static_cast<LoadParser*>(parser);
    try{
        if(p -> properCommand()){
            p -> prepareCommand();
        }
    }
    catch (const std::invalid_argument &e){
        throw;
    }
}

size_t Load::exe(Parser *parser) {
    FileReader readerDNA((parser->getDetails()).c_str());
    MetaData *item = new MetaData(readerDNA.readData(), parser->getName());
    App::m_data.addDNA(item);
    return item->m_id;
}
