#include <iostream>
#include <algorithm>
#include <vector>
#include "printSTL.h"
using namespace std;

int main(){

    vector<int> v = {3,1,2,1,3,1,2,1};
    vector<int> v2;
    v2.reserve(100);
    unsigned int i = 0;
    while(v2.size() != 100){
        
        if(i == v.size()){
                i = 0;
            }
        v2.push_back(v.at(i));
        
        i++;
    }    
    printSTL(v2, " ", true);


    return 0;
}


//3 1 2 1 3 1 2 1