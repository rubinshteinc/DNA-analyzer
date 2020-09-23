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
    const std::string& getFilename() const;
    const std::string& getID() const;
    void pushID(const std::string& name);

    size_t size() const;
    void pushName(size_t pos, const std::string& name);

private:
    std::vector<std::string> _arguments;
};

inline const std::string& Args::getCommandName() const{
    return _arguments[COMMAND];
}


inline size_t Args::size() const{
    return _arguments.size();
}

inline void Args::pushName(size_t pos, const std::string &name){
    std::vector<std::string>::iterator it = _arguments.begin() + pos;
    _arguments.insert(it, name);
}


inline const std::string& Args::getName() const{
    return _arguments[NAME];
}

inline const std::string& Args::getSeq() const{
    return _arguments[DNA_SEQ];
}
inline const std::string& Args::getFilename() const{
    return _arguments[1];
}


inline const std::string& Args::getID() const{
    return _arguments[1];

}
inline void Args::pushID(const std::string &ID) {
    _arguments[1] = ID;
}

#endif //DNA_ANALYZER_ARGS_H
