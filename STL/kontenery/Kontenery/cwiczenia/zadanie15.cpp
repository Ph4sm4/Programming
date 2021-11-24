#include <iostream>
#include <algorithm>
#include <vector>
#include "printSTL.h"
using namespace std;

int main(){

    vector<int> v;
    v.reserve(100);
    int cur = 1;
    while(v.size() != 100){
        for(int i = 0; i<cur; i++){
              v.push_back(cur);
              if(v.size() == 100){
                  break;
              }
        }
        cur++;
        
    }

    printSTL(v, " ", true);

    return 0;
}