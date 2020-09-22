//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_METADATA_H
#define DNA_ANALYZER_METADATA_H

#include <cstddef>
#include <string>

class DNASeq;


class MetaData{
public:
    MetaData(const std::string &seq, const std::string &name);
    ~MetaData();
    size_t getID() const;
    std::string getName() const;
    DNASeq* getSeq() const;
    void setName(std::string &newName);
private:

    DNASeq *_seq;
    std::string _name;
    size_t _id;
    char _status;

    static size_t _idCount;

};


inline size_t MetaData::getID() const{
    return _id;
}

inline std::string MetaData::getName() const{
    return _name;
}

inline DNASeq* MetaData::getSeq() const{
    return _seq;
}

inline void MetaData::setName(std::string &newName) {
    _name = newName;
}
#endif //DNA_ANALYZER_METADATA_H
