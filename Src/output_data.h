#ifndef DNA_SEQUENCE_OUTPUT_DATA_H
#define DNA_SEQUENCE_OUTPUT_DATA_H
#include <fstream>
class IOutput{
public:
    virtual void write(std::string &data) = 0;
    virtual ~IOutput(){}
};

class OutputFile :public IOutput{
public:
    OutputFile(std::string &fileName);
    void write(std::string &data);

private:
    std::string m_fileName;
};

class OutputConsole : public IOutput{
public:
    void write(std::string &data);
    ~OutputConsole(){}
};
#endif //DNA_SEQUENCE_OUTPUT_DATA_H
