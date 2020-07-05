#include "terminal.h"
#include "parsing.h"
#include "meta_data.h"
#include "factory_command.h"
#include "Icommand.h"
#include "input_data.h"
#include "output_data.h"

void Terminal::run()
{
    std::vector <MetaData*> m_data;
    std::string prompt = "cmd >>";
    bool flag = true;
    Parsing p;
    FactoryCLI f;
    ICommand *command;
    Input *reader = reinterpret_cast<Input *>(new InputConsole);
    IOutput *writer = reinterpret_cast<IOutput *>(new OutputConsole);
    std::string input;
    std::vector<std::string> params;
    MetaData *data;
    for(size_t i = 0; i < 3; ++i){
        writer -> write(prompt);
        input = reader -> readData();
        params = p.parserInput(input);
        command = f.managementCLI(params[0]);
        data = command -> exe(params[1], params[2]);
        m_data.push_back(data);
        delete command;
    }

}