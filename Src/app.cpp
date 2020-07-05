#include "app.h"
#include <iterator>

void App::start() {
    m_terminal.run();
}


void App::addData(MetaData *data){
    m_data -> push_back(data);
}

App::~App() {
    for (std::vector<MetaData *>::iterator it = m_data->begin(); it != m_data->end(); ++it) {
        delete[] *it;
    }
    delete m_data;
}