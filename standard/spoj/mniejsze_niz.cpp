#include <iostream>
#include <set>
#include <array>
#include <iterator>
#include "printSTL.h"
using namespace std;

int main(){

    cout<<"Podaj wielkosc zbioru: ";
    int wielkosc;
    cin>>wielkosc;
    multiset<int, greater<int>> zbior;
    for(int i = 0; i < wielkosc; i++){
        cout<<"Podaj "<<i+1<<" wartosc: ";
        int temp = 0;
        cin>>temp;
        zbior.insert(temp);
    }
    cin.get();
    cout<<"Podaj liczbe elementow do porownania: ";
    int liczba_porownan;
    cin>>liczba_porownan;

    int *tab;
    tab = new int [liczba_porownan];
    int *tab2;
    tab2 = new int [liczba_porownan];

    for(int i = 0; i < liczba_porownan; i++){
        cout<<"Podaj "<<i+1<<" element: ";
        cin>>tab[i];
        tab2[i] = 0;
    }

    printSTL(zbior, " ", true);

    for(int i = 0; i < liczba_porownan; i++){
        set<int, greater<int>>::iterator it = zbior.end();
        --it;
        for(int j = 0; j < wielkosc; j++){
            if(tab[i] > *it){
                tab2[i]++;
                it--;
            }
        }
    }

    for(int i = 0; i < liczba_porownan; i++){
        cout<<tab2[i]<<endl;
    }


    return 0;
}