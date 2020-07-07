#include "app.h"
#include <iterator>

void App::start() {
    Terminal::run();
}


App::~App() {
    std::vector<MetaData *>::iterator it = m_data.begin();
    for (;it != m_data.end(); ++it) {
        delete[] (*it);
    }
}