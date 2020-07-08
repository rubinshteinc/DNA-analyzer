#ifndef DNA___ANALYZER_TERMINAL_H
#define DNA___ANALYZER_TERMINAL_H

class IReader;
class IWriter;

class Terminal{
public:
    Terminal(IReader *pReader, IWriter *pWriter);
    void run();

private:
    static std::string m_prompt;
    IReader *m_pIReader;
    IWriter *m_IWriter;
};

#endif //DNA___ANALYZER_TERMINAL_H
