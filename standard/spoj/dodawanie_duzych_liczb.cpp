#include <iostream>
#include <vector>
#include "printSTL.h"
using namespace std;

int main(){

    cout<<"Podaj liczbe par: ";
    int liczba;
    cin>>liczba;

    vector<unsigned long long int> suma;

    for(int i = 0; i < liczba; i++){
        pair<unsigned long long int, unsigned long long int> temp;
        cout<<"Enter "<<i+1<<" pair of numbers"<<endl;
        cin>>temp.first>>temp.second;
        auto lambda = [temp](){return temp.first + temp.second;};
        suma.push_back(lambda());
    }

    printSTL(suma, "\n");

    return 0;
}