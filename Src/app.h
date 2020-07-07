#ifndef DNA___ANALYZER_APP_H
#define DNA___ANALYZER_APP_H
#include "meta_data.h"
#include "terminal.h"
#include <vector>

class App{
public:
    ~App();
    void start();
    const std::vector<MetaData*>* getData(){ return &m_data;}
private:
    std::vector<MetaData*> m_data;

};

#endif //DNA___ANALYZER_APP_H
