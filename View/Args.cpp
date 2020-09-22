//
// Created by a on 9/16/20.
//

#include <iterator>
#include <sstream>
#include "Args.h"


Args::Args(std::string &input){
    parser(input);
}


void Args::parser(std::string &input) {
    std::istringstream iss(input);
    copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         back_inserter(_arguments));
}