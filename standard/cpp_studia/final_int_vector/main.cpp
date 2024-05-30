#include <iostream>
#include "IntVector.h"
using namespace std;

bool specialCount(IntVector *source[], int n, int &base, int &derived)
{
    for (int i = 0; i < n; i++)
    {
        if (dynamic_cast<StringIntVector *>(source[i]))
            base++;
        else
            derived++;
    }
}

int main()
{
    IntVector v;
    StringIntVector vString;
    Node node3(345);
    Node node2(123);
    Node node1(5);

    node1.next = &node2;

    node2.prev = &node1;
    node2.next = &node3;

    node3.prev = &node2;

    v.pHead = &node1;
    vString.pHead = &node1;

    int countOfBaseClass = 0;
    int countOfDerivedClass = 0;
    const int arrSize = 4;
    IntVector *pointers[arrSize] = {&v, &v, &vString, &vString};

    specialCount(pointers, arrSize, countOfBaseClass, countOfDerivedClass);

    cout << "Counted base: " << countOfBaseClass << endl;
    cout << "Count derived: " << countOfDerivedClass << endl;

    try
    {
        int ind;
        cout << "Input index: ";
        cin >> ind;

        int val = v[ind];

        cout << "Value: " << val << endl;

        int val2 = vString["aa"];
        cout << "Value using string: " << val2 << endl;
    }
    catch (runtime_error err)
    {
        cout << err.what() << endl;
    }

    return 0;
}