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

        if(cmd == "exit"){
            flag = false;
            continue;
        }
        parser.parserInput(cmd);

        try{
            command = FactoryCLI::managementCLI(&parser);
           id = command -> exe(&parser);
           App::m_data.print(id);
        }
       catch(const std::exception &e){
           std::cout << e.what() << std::endl;
       }
       delete command;
    }

}