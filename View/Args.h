//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_ARGS_H
#define DNA_ANALYZER_ARGS_H

#include <vector>
#include <string>

enum {
    COMMAND, DNA_SEQ, NAME
};


class Args{
public:
    Args(std::string &input);
    void parser(std::string &input);
    const std::string& getCommandName() const;
    const std::string& getName() const;
    const std::string& getSeq() const;

    size_t size() const;
    void pushName(size_t pos, std::string name);

private:
    std::vector<std::string> _arguments;
};

inline const std::string& Args::getCommandName() const{
    return _arguments[COMMAND];
}


inline size_t Args::size() const{
    return _arguments.size();
}

inline void Args::pushName(size_t pos, std::string name){
    std::vector<std::string>::iterator it = _arguments.begin() + pos;
    _arguments.insert(it, name);
}

inline const std::string& Args::getName() const{
    return _arguments[NAME];
}

inline const std::string& Args::getSeq() const{
    return _arguments[DNA_SEQ];
}

#endif //DNA_ANALYZER_ARGS_H
