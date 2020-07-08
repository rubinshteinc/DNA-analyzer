#ifndef DNA___ANALYZER_METE_DATA_H
#define DNA___ANALYZER_METE_DATA_H

#include <cstring>
#include <iostream>
#include <exception>
#include <vector>
#include "../I_O/input_data.h"
#include "../I_O/output_data.h"
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
    const char* getSeq(){return reinterpret_cast<const char *>(m_DNASequence);}
    ~DNASeq();
};


#endif //DNA___ANALYZER_METE_DATA_H
