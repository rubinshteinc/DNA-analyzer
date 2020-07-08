#ifndef DNA___ANALYZER_APP_H
#define DNA___ANALYZER_APP_H
#include "Data/meta_data.h"
#include "terminal.h"

class App{
public:
    App(IReader *pr, IWriter *pw);
    void start();
    static HashTableData m_data;

private:
    Terminal m_terminal;
};

#endif //DNA___ANALYZER_APP_H
