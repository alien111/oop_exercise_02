#include "BitString.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

BitString::BitString() {

    firstHalf = 0;
    secondHalf = 0;

}

BitString::BitString(const char * in) : BitString() {
    std::string str = std::string(in);
    std::string sec(str.size(), '0');
    std::vector<int> v;

    while (str != sec) {
        int a = 0;
        for (int i = 0; i < str.size(); i++) {
            a *= 10;
            a += str[i] - '0';
            str[i] = char('0' + a / 2);
            a %= 2;
        }
        v.push_back(a);
    }



    unsigned long long shs = 1;

    for (int i = 0; i < 64 && i < v.size(); i++) {
        secondHalf += v[i] * shs;
        shs *= 2;
    }

    unsigned long long fhs = 1;

    for (int i = 64; i < v.size(); i++) {
        firstHalf += v[i] * fhs;
        fhs *= 2;
    }

}

BitString::BitString(std::string str) : BitString() {
    std::string sec(str.size(), '0');
    std::vector<int> v;

    while (str != sec) {
        int a = 0;
        for (int i = 0; i < str.size(); i++) {
            a *= 10;
            a += str[i] - '0';
            str[i] = char('0' + a / 2);
            a %= 2;
        }
        v.push_back(a);
    }



    unsigned long long shs = 1;

    for (int i = 0; i < 64 && i < v.size(); i++) {
        secondHalf += v[i] * shs;
        shs *= 2;
    }

    unsigned long long fhs = 1;

    for (int i = 64; i < v.size(); i++) {
        firstHalf += v[i] * fhs;
        fhs *= 2;
    }
}

void BitString::input(std::istream &is) {
    std::string str;

    
    is >> str;

    std::string sec(str.size(), '0');
    std::vector<int> v;

    while (str != sec) {
        int a = 0;
        for (int i = 0; i < str.size(); i++) {
            a *= 10;
            a += str[i] - '0';
            str[i] = char('0' + a / 2);
            a %= 2;
        }
        v.push_back(a);
    }



    unsigned long long shs = 1;

    for (int i = 0; i < 64 && i < v.size(); i++) {
        secondHalf += v[i] * shs;
        shs *= 2;
    }

    unsigned long long fhs = 1;

    for (int i = 64; i < v.size(); i++) {
        firstHalf += v[i] * fhs;
        fhs *= 2;
    }
}

BitString BitString::operator ~ () const{
    BitString bs;

    bs.firstHalf = ~(firstHalf);
    bs.secondHalf = ~(secondHalf);

    return bs;
}


BitString BitString::operator & (const BitString &bs) const{
    
    BitString bs1;
    bs1.firstHalf = firstHalf & bs.firstHalf;
    bs1.secondHalf = secondHalf & bs.secondHalf;

    return bs1;
}

BitString BitString::operator | (const BitString &bs) const{
    BitString bs1;
    bs1.firstHalf = firstHalf | bs.firstHalf;
    bs1.secondHalf = secondHalf | bs.secondHalf;

    return bs1;
}

BitString BitString::operator ^ (const BitString &bs) const{
    
    BitString bs1;
    bs1.firstHalf = firstHalf ^ bs.firstHalf;
    bs1.secondHalf = secondHalf ^ bs.secondHalf;

    return bs1;
}

void BitString::operator << (unsigned long long size) {
    unsigned long long pow63 = 1;
    for (int i = 0; i < 63; i++) {
        pow63 *= 2;
    }

    for (int i = 0; i < size; i++) {                                          //110100111 << 3 == 100111000
        firstHalf = firstHalf << 1;
        if (secondHalf >= pow63) {
            firstHalf += 1;
        }
        secondHalf = secondHalf << 1;
    }
}

void BitString::operator >> (unsigned long long size) {
    
    unsigned long long pow63 = 1;
    for (int i = 0; i < 63; i++) {
        pow63 *= 2;
    }
    for (int i = 0; i < size; i++) {
        secondHalf = secondHalf >> 1;
        if (firstHalf % 2 == 1) {
            secondHalf += pow63;
        }
        firstHalf = firstHalf >> 1;
    }


}

unsigned long long BitString::posBitNumber() const{

    BitString bs1;
    bs1.firstHalf = firstHalf;
    bs1.secondHalf = secondHalf;

    unsigned long long number = 0;

    while (bs1.firstHalf != 0) {
        if (bs1.firstHalf % 2 == 1) number++;
        bs1.firstHalf /= 2;
    }

    while (bs1.secondHalf != 0) {
        if (bs1.secondHalf % 2 == 1) number++;
        bs1.secondHalf /= 2;
    }

    return number;

}

bool BitString::operator == (BitString &bs) const{
    unsigned long long thisNumber = posBitNumber();
    unsigned long long bsNumber = bs.posBitNumber();

    return thisNumber == bsNumber;
}

bool BitString::operator > (BitString &bs) const{
    unsigned long long thisNumber = posBitNumber();
    unsigned long long bsNumber = bs.posBitNumber();

    return thisNumber > bsNumber;
}

bool BitString::operator < (BitString &bs) const{
    unsigned long long thisNumber = posBitNumber();
    unsigned long long bsNumber = bs.posBitNumber();

    return thisNumber < bsNumber;
}

bool BitString::isArgInThis(const BitString &bs) const{

    BitString ans;
    ans.firstHalf = firstHalf & bs.firstHalf;
    ans.secondHalf = secondHalf & bs.secondHalf;
    if (ans.firstHalf == bs.firstHalf && ans.secondHalf == bs.secondHalf) return true;
    else return false;

}

void BitString::print(std::ostream &os) const{

    BitString bs1;
    bs1.firstHalf = firstHalf;
    bs1.secondHalf = secondHalf;

    std::vector<int> v;

    while (bs1.firstHalf != 0) {
        v.push_back(bs1.firstHalf % 2);
        bs1.firstHalf /= 2;
    }

    for (int i = 0; i < 64 - v.size(); i++) {
        std::cout << 0;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        std::cout << v[i];
    }
    v.clear();

    std::cout << " ";

    while (bs1.secondHalf != 0) {
        v.push_back(bs1.secondHalf % 2);
        bs1.secondHalf /= 2;
    }
    for (int i = 0; i < 64 - v.size(); i++) {
        os << 0;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        os << v[i];
    }
    std::cout << '\n';

}

BitString operator ""_bs(const char * in) {
    return BitString(in);
}


std::istream & operator>> (std::istream& is, BitString& bs) {
    std::string a;
    is >> a;

    bs = BitString(a);
}

std::ostream & operator<< (std::ostream& os, const BitString& bs) {
    bs.print(os);
}