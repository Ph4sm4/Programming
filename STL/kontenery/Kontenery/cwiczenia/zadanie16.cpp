#include <iostream>
#include <algorithm>
#include <vector>
#include "printSTL.h"
using namespace std;

int main(){

    vector<int> v;
    v.reserve(100);
    int minus = 0;
    int start = 100;
    while(v.size() != 100){
        int sum = start - minus;
        v.push_back(sum);
        minus++;
        start = sum;
    }

    printSTL(v, " ", true);

    return 0;
}

//100 99 97 94 90 85