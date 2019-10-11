#ifndef __BitString_h__
#define __BitString_h__


#include <iostream>
#include <string>

class BitString
{
public:

    BitString();
    BitString(const char *);

    void input(std::istream &is);

    BitString operator ~ ();
    BitString operator & (const BitString &bs);
    BitString operator | (const BitString &bs);
    BitString operator ^ (const BitString &bs);
    void operator >> (unsigned long long size);
    void operator << (unsigned long long size);
    bool operator == (BitString &bs);
    bool operator > (BitString &bs);
    bool operator < (BitString &bs);

    unsigned long long posBitNumber();
    int compPosBitNumber(const BitString &bs);

    bool isArgInThis(const BitString &bs);

    void print(std::ostream &os);


private:
    unsigned long long firstHalf;
    unsigned long long secondHalf;
    
    
};

BitString operator ""_bs(const char * in);

#endif