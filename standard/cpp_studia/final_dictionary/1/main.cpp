#include <iostream>
#include <string>
#include "dictionary.h"

using namespace std;

int main()
{
    Dictionary<int, string> dict;
    DictionaryItem<int, string> item1(65, string("adriankuuuuu"));
    DictionaryItem<int, string> item2(14, string("siencia"), &item1);

    dict.pHead = &item2;

    cout << dict << endl;

    Dictionary<int, string> dict2 = dict;
    cout << "dict2: " << dict2;

    return 0;
}
