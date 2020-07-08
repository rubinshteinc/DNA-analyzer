#include "app.h"

HashTableData App::m_data;


App::App(IReader *pr, IWriter *pw):m_terminal(pr, pw){

}


void App::start() {
    m_terminal.run();
}
