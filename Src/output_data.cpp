#include "output_data.h"
#include <iostream>
OutputFile::OutputFile(std::string &fileName):m_fileName(fileName){}

void OutputFile::write(std::string &data){

}


void OutputConsole::write(std::string &data){
    std::cout << data;
}
