
#include <iostream>
#include <string>

class BitString
{
public:

    BitString();
    BitString(const char *);

    void Enter();

    BitString operator ~ ();
    BitString operator & (BitString &bs);
    BitString operator | (BitString &bs);
    BitString operator ^ (BitString &bs);
    void operator >> (unsigned long long size);
    void operator << (unsigned long long size);
    bool operator == (BitString &bs);
    bool operator > (BitString &bs);
    bool operator < (BitString &bs);

    unsigned long long posBitNumber();
    int compPosBitNumber(BitString &bs);

    void isArgInThis(BitString &bs);

    void print();


private:
    unsigned long long firstHalf;
    unsigned long long secondHalf;
    
    
};

