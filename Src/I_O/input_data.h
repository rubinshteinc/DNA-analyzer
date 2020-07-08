#ifndef DNA_SEQUENCE_INPUT_DATA_H
#define DNA_SEQUENCE_INPUT_DATA_H
#include <string>

class IReader{
public:
    virtual std::string readData() = 0;
    virtual ~IReader(){}
};

class FileReader : public IReader
{
public:
    FileReader(const char *fileName);
    virtual ~FileReader(){}
    virtual std::string readData();

private:
   const char *m_fileName;
};



class ConsuleReader: public IReader{
public:
    virtual ~ConsuleReader(){}
    virtual std::string readData();
};

#endif //DNA_SEQUENCE_INPUT_DATA_H
