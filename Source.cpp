#include "BitString.h"

int main(int argc, char** argv) {

    BitString bs;

    std::cout << "Enter string\n";

    bs.input(std::cin);

    BitString bs1;


    std::cout << "Enter string\n";
    bs1.input(std::cin);

    bs.print(std::cout);
    bs1.print(std::cout);

    BitString bsTest = ~bs;

    std::cout << "not first number:\n";

    bsTest.print(std::cout);

    bsTest = bs & bs1;

    std::cout << "first and second:\n";

    bsTest.print(std::cout);

    bsTest = bs | bs1;

    std::cout << "first or second:\n";

    bsTest.print(std::cout);
    
    bsTest = bs ^ bs1;

    std::cout << "first xor second:\n";

    bsTest.print(std::cout);

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
    bs.print(std::cout);

    bs1 >> shift;

    std::cout << "Shifted second right : \n";
    bs1.print(std::cout); 

    std::cout << "Literal using 123_bs : \n";
    (123_bs).print(std::cout);

    

    return 0;
}