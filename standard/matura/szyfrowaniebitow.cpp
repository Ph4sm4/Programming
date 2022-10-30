#include <iostream>
using namespace std;

/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1ULL << (b)))
#define BIT_FLIP(a, b) ((a) ^= (1ULL << (b)))
#define BIT_CHECK(a, b) (!!((a) & (1ULL << (b)))) // '!!' to make sure this returns 0 or 1

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))

/*
n is the nth bit


checking a bit: bit = (number >> n) & 1U;

clearing a bit: number &= ~(1UL << n);

setting a bit: number |= 1UL << n;

*/

string encrypt(const string input)
{
    string output = "";

    for (int i = 0; i < input.length(); i++)
    {
        int c = input[i];
        /*
        following variables are responsible for holding informations about 6 last bits, but split in half, so for number

        100 - 01100100 (2)

        secondPart
        etc. will hold info about the bits 100 (so bits at indexes 3, 4, 5) so first 3 bits from the first pair of 3 bits looking from the end (technically from the start)

        firstPart
        etc. will hold info about the bits 100 (so bits at indexes 0, 1, 2) so first 3 bits from the second pair of 3 bits looking from the end (technically from the start)
        */

        for (int j = 0; j < 3; j++)
        {
            short firstPart = (c >> (j)) & 1U;
            short secondPart = (c >> (j + 3)) & 1U;

            if (firstPart == secondPart)
                c &= ~(1UL << (j)); // clearing this bit
            else
                c |= 1UL << (j); // setting this bit
        }

        // after we are done setting the bits, we have to invert the order of the last 3 bits, for instance: 100 would become 001
        short firstBit = (c >> (0)) & 1U;
        short thirdBit = (c >> (2)) & 1U;
        short tempBit = firstBit;
        firstBit = thirdBit;
        thirdBit = tempBit;

        (firstBit ? c |= 1UL << 0 : c &= ~(1UL << (0)));
        (thirdBit ? c |= 1UL << 2 : c &= ~(1UL << (2)));

        output += c;
    }

    return output;
}

string decrypt(const string input)
{
    string output = "";

    for (int i = 0; i < input.length(); i++)
    {
        int c = input[i];

        // first we need to undo the reversal of order in the last 3 bits

        short firstBit = (c >> (0)) & 1U;
        short thirdBit = (c >> (2)) & 1U;
        short tempBit = firstBit;
        firstBit = thirdBit;
        thirdBit = tempBit;

        (firstBit ? c |= 1UL << 0 : c &= ~(1UL << (0)));
        (thirdBit ? c |= 1UL << 2 : c &= ~(1UL << (2)));

        for (int j = 0; j < 3; j++)
        {
            short firstPart = (c >> (j)) & 1U;
            short secondPart = (c >> (j + 3)) & 1U;

            /*
             after we came back to the proper order of bits, we can evaluate the value that was previously on this place
             by simply checking the according bit in the first part, if the bit in the first is 1 and the bit in the second part is 0, then those bits where the same
             and so we should set this bit to the same value as the first one's

             otherwise if the bit in the first part is 1 and the bit in the second part is 1 aswell, then those bits were not the same
             and so we should set this bit to the opposite value of the first one's
             */

            if (secondPart == 0)
                (firstPart ? c |= 1UL << (j) : c &= ~(1UL << (j)));
            else
                (firstPart ? c &= ~(1UL << (j)) : c |= 1UL << (j));
        }

        output += c;
    }

    return output;
}

int main()
{

    const string toDecrypt = "Je}`{!sqjfqeh!odur!r{lkj!ne!r{ld!`jcq{!ne!ild!odur!sq}{`ern{%";
    const string toEncrypt = "Kazdy program jest tylko na tyle dobry na ile jest przydatny!";

    cout << "Decrypted: " << decrypt(toDecrypt) << endl;
    cout << "Encrypted: " << encrypt(toEncrypt) << endl;

    return 0;
}