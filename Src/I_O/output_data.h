#ifndef DNA_SEQUENCE_OUTPUT_DATA_H
#define DNA_SEQUENCE_OUTPUT_DATA_H
#include <fstream>

class IWriter{
public:
    virtual void write(std::string &data) = 0;
    virtual ~IWriter(){}
};

class FileWriter : public IWriter{
public:
    FileWriter(std::string &fileName);
    virtual ~FileWriter(){}
   virtual void write(std::string &data);

private:
    std::string m_fileName;
};

class ConsuleWriter : public IWriter{
public:
    virtual void write(std::string &data);
    virtual ~ConsuleWriter(){}
};
#endif //DNA_SEQUENCE_OUTPUT_DATA_H
