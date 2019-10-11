#include "BitString.h"

int main(int argc, char** argv) {

    BitString bs;

    std::cout << "Enter string\n";

    std::cin >> bs;

    BitString bs1;


    std::cout << "Enter string\n";
    std::cin >> bs1;

    std::cout << bs;
    std::cout << bs1;

    BitString bsTest = ~bs;

    std::cout << "not first number:\n";

    std::cout << bsTest;

    bsTest = bs & bs1;

    std::cout << "first and second:\n";

    std::cout << bsTest;

    bsTest = bs | bs1;

    std::cout << "first or second:\n";

    std::cout << bsTest;
    
    bsTest = bs ^ bs1;

    std::cout << "first xor second:\n";

    std::cout << bsTest;

    std::cout << "Positive Bit Number of First is " << bs.posBitNumber() << '\n';

    if (bs > bs1) {
        std::cout << "Bit Comparence of first and second shows that first is larger\n";
    } else if (bs < bs1) {
        std::cout << "Bit Comparence of first and second shows that second is larger\n";
    } else {
        std::cout << "Bit Comparence of first and second shows that they are equal\n";
    }

    std::cout << "Is second in first? : ";
    if (bs.isArgInThis(bs1)) std::cout << "YES\n";
    else std::cout << "NO\n";

    int shift;

    std::cout << "Enter number of bits to shift first number left and second right : ";
    std::cin >> shift;

    bs << shift;

    std::cout << "Shifted first left : \n";
    std::cout << bs;

    bs1 >> shift;

    std::cout << "Shifted second right : \n";
    std::cout << bs1;

    std::cout << "Literal using 123_bs : \n";
    std::cout << 123_bs;

    BitString bs2;

    std::cin >> bs2;
    std::cout << bs2;

    return 0;
}