#ifndef DNA___ANALYZER_APP_H
#define DNA___ANALYZER_APP_H
#include "terminal.h"
#include "meta_data.h"
#include <vector>
class App{
public:
    App(){m_data = new std::vector<MetaData*>;}
    ~App();
    void start();
    void addData(MetaData *data);
    std::vector<MetaData*> *m_data;

private:
    Terminal m_terminal;
};

#endif //DNA___ANALYZER_APP_H
