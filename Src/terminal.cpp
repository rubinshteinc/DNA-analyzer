#include "terminal.h"
#include "parsing.h"
#include "factory_command.h"
#include "Icommand.h"
#include "input_data.h"
#include "output_data.h"

void Terminal::run()
{
    std::string prompt = "cmd >>";
    bool flag = true;
    Parser parser;
    ICommand *command;
    Input *reader = reinterpret_cast<Input *>(new InputConsole);
    IOutput *writer = reinterpret_cast<IOutput *>(new OutputConsole);
    std::string input;
    MetaData *data;
    while(flag){
        writer -> write(prompt);
        parser.parserInput(reader -> readData());
        command = FactoryCLI::managementCLI(parser);
        data = command -> exe(parser);
//        std::cout << "[" << data->m_id << "]";
//        std::cout << data -> m_seq;
//        std::cout << data -> m_name;
        delete command;
    }

}