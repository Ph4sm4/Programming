#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "printSTL.h"
using namespace std;

int main(){

    pair<int, int> p (6 , 2);
    vector<int> v;
    v.reserve(100);

    while(v.size() != 100){

        v.push_back(p.first);
        v.push_back(p.second);
        p.first += 2;
        p.second += 1;

    }
    printSTL(v, " ", true);

    return 0;
}