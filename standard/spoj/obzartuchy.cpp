#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include "printSTL.h"
using namespace std;

int main(){

    cout<<"Podaj liczbe zestawow: ";
    int liczba_zestawow;
    cin>>liczba_zestawow;

    vector<int> wynik;
    
    
    for(int i = 0; i < liczba_zestawow; i++){
        cout<<"Podaj liczbe ob¾artuch¢w i liczbe ciastek(oddzielone spacja): ";
        double liczba_obz, liczba_ciastek;
        cin>>liczba_obz>>liczba_ciastek;

        double temp_sum = 0;

        for(int j = 0; j < liczba_obz; j++){
            int temp;
            cin>>temp;
            temp_sum += floor(86400/temp);
        }
        
        wynik.push_back(ceil(temp_sum/liczba_ciastek));

    }

    printSTL(wynik, "\n");

    return 0;
}