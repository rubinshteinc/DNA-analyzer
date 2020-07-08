#include "output_data.h"
#include <iostream>

FileWriter::FileWriter(std::string &fileName): m_fileName(fileName){}

void FileWriter::write(std::string &data){

}


void ConsuleWriter::write(std::string &data){
    std::cout << data;
}
