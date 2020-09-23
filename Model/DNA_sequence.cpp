//
// Created by a on 9/16/20.
//

#include <stdexcept>
#include <cstring>

#include "DNA_sequence.h"


//#include <fstream>
//#include <sstream>
//#include <algorithm>
//
//static int DNACompare(const DNASeq &lhs, const DNASeq &rhs)
//{
//    for(size_t i = 0; i < lhs.getLength() and i < rhs.getLength(); ++i)
//    {
//        if(lhs[i] != rhs[i])
//            return int(&lhs - &rhs);
//    }
//    if(lhs.getLength() == rhs.getLength())
//        return  0;
//
//    return int(&lhs - &rhs);
//}
//

DNASeq::DNASeq(const char *sequence):m_DNASequence(NULL)
{
    init(sequence);
}

DNASeq::DNASeq(const std::string& sequence):m_DNASequence(NULL)
{
    init(sequence.c_str());
}

//DNASeq::DNASeq(IReader *input):m_DNASequence(NULL){
//    const char *sequence = input->readData();
//    init(sequence);
//}
//

//DNASeq::DNASeq(const DNASeq &sequence):m_DNASequence(NULL)
//{
//    m_DNASequence =  new Nucleotide[sequence.m_length + 1];
//    unsigned int i;
//    for(i = 0; i < sequence.m_length; ++i)
//        m_DNASequence[i] = sequence[i];
//    m_DNASequence[i] = '\0';
//
//    m_length = sequence.m_length;
//}



DNASeq::DNASeq(size_t size)
{
    m_DNASequence = new Nucleotide[size];
    m_length = size;
}


DNASeq::~DNASeq() {
    delete[](m_DNASequence);
    m_DNASequence = NULL;

}

//
//void DNASeq::writeDNADataToFile(const char* fileName)
//{
//    std::ofstream DNAFile;
//    DNAFile.open (fileName);
//    if(DNAFile.is_open())
//        DNAFile << m_DNASequence;
//    DNAFile.close();
//}
//

DNASeq& DNASeq::operator=(const DNASeq &other){
    if (this != &other)
    {
        Nucleotide *newDNASeq =  new Nucleotide[other.getLength() + 1];
        for(unsigned int i = 0; i < other.m_length; ++i)
            newDNASeq[i].m_nucleotide = other[i];
        newDNASeq[other.m_length].m_nucleotide = '\0';

        delete[] m_DNASequence;
        m_DNASequence = newDNASeq;
        m_length = other.getLength();
    }
    return *this;
}

DNASeq::Nucleotide& DNASeq::operator[](size_t index)const
{
    if (index >= m_length)
        throw std::length_error("The index out of range");
    return m_DNASequence[index];
}

//std::ostream& operator<<(std::ostream &os, DNASeq &sequence)
//{
//    for (unsigned i = 0; i < sequence.m_length; ++i)
//        os << sequence[i];
//    return os;
//}
//
//


DNASeq DNASeq::slice(size_t startIndex, size_t endIndex)const
{
    DNASeq seq(endIndex - startIndex + 1);
    size_t j, i;
    for (j = 0, i = startIndex; i < endIndex; ++i, ++j)
        seq.m_DNASequence[j] = m_DNASequence[i];

    seq.m_DNASequence[j] = '\0';

    return seq;
}
//
//DNASeq DNASeq::getPairedStrand()const
//{
//    DNASeq seq(m_length);
//    for(size_t i = 0; i < m_length; ++i)
//        seq.m_DNASequence[i] = m_DNASequence[m_length - i - 1].getStrand();
//    return seq;
//}
//
//int DNASeq::find(DNASeq &seq, size_t index /*=0*/)
//{
//    for (size_t i = index; i < m_length; ++i)
//    {
//        if(slice(i, i + seq.m_length) == seq)
//            return (int)i;
//    }
//    return -1;
//}
//
//size_t DNASeq::count(DNASeq &seq)
//{
//    size_t count = 0;
//    for(int i = find(seq); 0 <= i and  i < (int)m_length; i = find(seq, i+1))
//    {
//        count++;
//    }
//    return count;
//}
//
//std::vector<size_t> DNASeq::findAll(DNASeq &seq)
//{
//    std::vector<size_t>index;
//    for(int i = find(seq); 0 <= i and i < (int)m_length; i = find(seq, i+1))
//    {
//        index.push_back(i);
//    }
//    return index;
//}
//
//std::vector<size_t> DNASeq::findConsensusSequences()
//{
//    DNASeq startCodon("ATG");
//    DNASeq endCodon1("TGA");
//    DNASeq endCodon2("TAA");
//    DNASeq endCodon3("TAG");
//
//    std::vector<size_t> startCodonIndexes = findAll(startCodon);
//    int endCodonIndex;
//    size_t lengthStartCodonIndexes = startCodonIndexes.size();
//
//    std::vector<size_t> res;
//    for (size_t i =0; i < lengthStartCodonIndexes; ++i){
//
//        endCodonIndex = find(endCodon1, (startCodonIndexes[i] + 3));
//        if(endCodonIndex != -1 && (endCodonIndex - startCodonIndexes[i])%3 == 0){
//            res.push_back(startCodonIndexes[i]);
//            continue;
//        }
//
//        endCodonIndex = find(endCodon2, (startCodonIndexes[i] + 3));
//        if(endCodonIndex != -1 && (endCodonIndex - startCodonIndexes[i])%3 == 0){
//            res.push_back(startCodonIndexes[i]);
//            continue;
//        }
//
//        endCodonIndex = find(endCodon3, (startCodonIndexes[i] + 3));
//        if(endCodonIndex != -1 && (endCodonIndex - startCodonIndexes[i])%3 == 0){
//            res.push_back(startCodonIndexes[i]);
//            continue;
//        }
//    }
//        return res;
//}
//

void DNASeq::init(const char *sequence)
{
    if(!isValid(sequence))
        throw std::invalid_argument("The DNASeq sequence is NOT valid!");

    size_t i;
    m_DNASequence =  new Nucleotide[strlen(sequence) + 1];
    m_length = strlen(sequence);
    for(i = 0; i < m_length; ++i)
        m_DNASequence[i] = sequence[i];

    m_DNASequence[i] = '\0';
}

bool DNASeq::isValid(const char *sequence)
{
    if(sequence)
    {
        for(unsigned int i = 0; i < strlen(sequence); i++)
            switch(sequence[i])
            {
                case 'A': break;
                case 'T': break;
                case 'C': break;
                case 'G': break;
                default:
                    return false;
            }
        return true;
    }
    return false;
}

bool DNASeq::isValid(char ch)
{
    if(ch)
    {
        switch(ch)
        {
            case 'A': break;
            case 'T': break;
            case 'C': break;
            case 'G': break;
            default:
                return false;
        }
        return true;
    }
    return false;
}


//bool operator==(const DNASeq &lhs, const DNASeq &rhs)
//{
//    return (!DNACompare(lhs, rhs));
//}
//
//bool operator!=(const DNASeq &lhs, const DNASeq &rhs)
//{
//    return (DNACompare(lhs, rhs));
//}
//
//


char DNASeq::Nucleotide::getStrand()const
{
    switch(m_nucleotide)
    {
        case 'A':return 'T';
        case 'T':return 'A';
        case 'C':return 'G';
        case 'G':return 'C';
    }
    return '\0';
}

DNASeq::Nucleotide::Nucleotide(const char ch):m_nucleotide(ch){

}


//DNASeq::Nucleotide& DNASeq::Nucleotide::operator= (char ch)
//{
//    if(DNASeq::isValid(ch)) ////throw exception
//        m_nucleotide = ch;
//    return *this;
//}
