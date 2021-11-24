#include <iostream>
#include <list>
#include <iterator>
#include "printSTL.h"
using namespace std;

int main(){

    cout<<"Podaj ilosc miast: ";
    unsigned int miasta;
    cin>>miasta;
    vector<int> zysk;
    
    for(int i = 0; i < miasta; i++){
        int temp;
        cin>>temp;
        zysk.push_back(temp);
    }

    int max = 0;
    int max_temp = 0;
    
    for(int i = 0; i < miasta; i++){
        max_temp += zysk.at(i);
        if(max_temp < 0) max_temp = 0;
        if(max < max_temp) max = max_temp;
    }
    cout<<"Max: "<<max<<endl;
    

    return 0;
}