//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_DNA_SEQUENCE_H
#define DNA_ANALYZER_DNA_SEQUENCE_H

#include <cstddef>
#include <string>


class DNASeq {

private:

    class Nucleotide {
    public:
        Nucleotide():m_nucleotide('\0'){}
        Nucleotide(char ch);
//        Nucleotide &operator=(char ch);
        operator char() { return m_nucleotide; }
        char getStrand() const;
        char m_nucleotide;
    };

    DNASeq(size_t size);
    void init(const char *sequence);
    static bool isValid(const char *sequence);
    static bool isValid(char sequence);

    Nucleotide *m_DNASequence;
    size_t m_length;


public:

    DNASeq(const char *sequence);
    DNASeq(const std::string &sequence);
    DNASeq& operator=(const DNASeq &other);
    size_t getLength()const { return m_length;}
//    DNASeq(const DNASeq &sequence);
    const char* getSequence() const {return reinterpret_cast<const char *>(m_DNASequence);}
    DNASeq::Nucleotide& operator[](size_t index)const;
    DNASeq slice(size_t startIndex, size_t endIndex) const;
    bool tooLongSeq() const;
    ~DNASeq();
};


inline bool DNASeq::tooLongSeq() const{
    return m_length > 40;
}





#endif //DNA_ANALYZER_DNA_SEQUENCE_H
