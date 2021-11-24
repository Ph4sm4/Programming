#include <iostream>
using namespace std;

int liczba, podanaliczba, tab[100], i = 0;

int main(){

    cout<<"Podaj liczbe, ktora chcesz przeliczyc na system osemkowy: ";
    cin>>liczba;
    podanaliczba = liczba;

    while(liczba){
        tab[i++] = liczba%8;
        liczba = liczba/8;
    }
    cout<<"Liczba "<<podanaliczba<<" po przeliczeniu na system osemkowy: ";
    for(int j = i - 1; j>=0; j--){
        cout<<tab[j];
    }


return 0;}
