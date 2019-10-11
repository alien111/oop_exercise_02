#ifndef __BitString_h__
#define __BitString_h__


#include <iostream>
#include <string>

class BitString
{
public:

    BitString();
    BitString(const char *);
    BitString(std::string);

    void input(std::istream &is);

    BitString operator ~ () const;
    BitString operator & (const BitString &bs) const;
    BitString operator | (const BitString &bs) const;
    BitString operator ^ (const BitString &bs) const;
    void operator >> (unsigned long long size);
    void operator << (unsigned long long size);
    bool operator == (BitString &bs) const;
    bool operator > (BitString &bs) const;
    bool operator < (BitString &bs) const;

    unsigned long long posBitNumber() const;
    int compPosBitNumber(const BitString &bs) const;

    bool isArgInThis(const BitString &bs) const;

    void print(std::ostream &os) const;

private:
    unsigned long long firstHalf;
    unsigned long long secondHalf;
    
    
};

BitString operator ""_bs(const char * in);

std::istream& operator>> (std::istream& is, BitString& bs);

std::ostream& operator<< (std::ostream& os, const BitString& bs); 


#endif