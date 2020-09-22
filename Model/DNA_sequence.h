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
        Nucleotide() {}
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
    size_t getLength(){ return m_length;}
//    DNASeq(const DNASeq &sequence);
    const char* getSequence(){return reinterpret_cast<const char *>(m_DNASequence);}
    ~DNASeq();
};


#endif //DNA_ANALYZER_DNA_SEQUENCE_H
