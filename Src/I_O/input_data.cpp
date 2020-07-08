#include "input_data.h"
#include <fstream>
#include <iostream>

FileReader::FileReader(const char *fileName): m_fileName(fileName){}

std::string FileReader::readData()
{
    std::string data;
    std::ifstream file((char*)(m_fileName));
    if (file.is_open())
    {
        getline(file, data);
        file.close();
    }
    else
        throw std::ios_base::failure("Error in opening the file");

    return data;
}


std::string ConsuleReader::readData(){
    std::string data;
    getline(std::cin , data);
    return data;
}
