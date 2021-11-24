#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include "printSTL.h"
using namespace std;

int main(){

    vector<int> x;
    back_inserter(x) = 100;
    back_inserter(x) = 200;
    printSTL(x, " ", true);

    x.reserve(x.size()*2);
    copy(x.begin(), x.end(), back_inserter(x));
    printSTL(x, " ", true);

    deque<int> y;
    front_inserter(y) = 300;
    front_inserter(y) = 400;
    copy(y.begin(), y.end(), front_inserter(y));
    printSTL(y, " ", true);


    ostream_iterator<int> out(cout, " : ");
    for(auto i : {1,2,3,4,5}){
        *out = i;
        out++;
    }
    cout<<endl;

    vector<int> data {1,2,3,4,5,6};
    copy(data.begin(), data.end(), out);
    cout<<endl;
    copy(data.begin(), data.end(), ostream_iterator<int>(cout, " <-> "));
    cout<<endl; 


    vector<int> fromUser;
    cout<<"Enter values that gonna be stored in vector: ";
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(fromUser));
    printSTL(fromUser, " ", true);

    return 0;
}