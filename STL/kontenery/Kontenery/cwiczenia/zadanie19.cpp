#include <iostream>
#include <algorithm>
#include <vector>
#include "printSTL.h"
using namespace std;

int main(){

    vector<int> v;
    vector<int> v2;

    for(int i = 0; i<1001; i++){
        v.push_back(i);
    }
    for(int i = 0; i<1001; i++){
        if(i%6==0){
            v2.push_back(i);
        }
    }
    printSTL(v, " ", true);
    cout<<endl<<endl<<endl;
    printSTL(v2, " ", true);

    return 0;
}