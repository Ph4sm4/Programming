#include <iostream>
#include "printSTL.h"
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void example();
void to_bin();

int main(){

    to_bin();

    return 0;
}

void example(){
    vector<int> fromUser;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(fromUser));

    ostream_iterator<int> out(cout, " ");
    for(auto i : fromUser){
        *out = i;
        out++;
    }
}

void to_bin(){

    cout<<"Enter a number: ";
    int num;
    cin>>num;

    list<int> bin;
    int current;
    while(num){
        current = num%2;
        bin.push_back(current);
        num = num / 2;
    }
    bin.reverse();

    ostream_iterator<int> out(cout, "");
    for(auto i : bin){
        *out = i;
        out++;
    }
}