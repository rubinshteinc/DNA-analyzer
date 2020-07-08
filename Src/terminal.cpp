#include "app.h"
#include "terminal.h"
#include "parsing.h"
#include "Command/factory_command.h"
#include "I_O/input_data.h"
#include "I_O/output_data.h"

std::string Terminal::m_prompt = "> cmd >>> ";

Terminal::Terminal(IReader *pReader, IWriter *pWriter):m_pIReader(pReader), m_IWriter(pWriter){
}


void Terminal::run()
{
    bool flag = true;
    Parser parser;
    ICommand *command;
    std::string cmd;
    size_t id;
    while(flag){
        m_IWriter -> write(m_prompt);
        cmd = m_pIReader -> readData();
        parser.parserInput(cmd);
        command = FactoryCLI::managementCLI(&parser);
        try{
            if(!command){
                flag = false;
                continue;
            }
           id = command -> exe(&parser);
           App::m_data.print(id);
        }
       catch(...){
           //complete
       }
       delete command;
    }

}