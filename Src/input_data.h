#ifndef DNA_SEQUENCE_INPUT_DATA_H
#define DNA_SEQUENCE_INPUT_DATA_H
#include <string>

class Input{
public:
    virtual std::string readData() = 0;
    virtual ~Input(){}
};

class InputFile : public Input
{
public:
    InputFile(const char *fileName);
    std::string readData();

private:
   const char *m_fileName;
};


class InputConsole: public Input{
public:
   std::string readData();
    ~InputConsole(){}
};

#endif //DNA_SEQUENCE_INPUT_DATA_H
