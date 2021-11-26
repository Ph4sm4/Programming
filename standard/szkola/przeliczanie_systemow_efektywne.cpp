#include <iostream>
#include <string>
using namespace std;


int main(){

    cout<<"Podaj system: ";
    unsigned int system, liczba;
    cin>>system;
    cout<<"Podaj dodatnia liczbe: ";
    cin>>liczba;

    string wynik;

    while(liczba){
        
        int r = liczba%system;
        if( r < 10){
            wynik = char('0' + r) + wynik;
        }
        else{
            wynik = char('A'-10 + r) + wynik;
        }    
        liczba /= system;
    }

    cout<<wynik<<endl;

    return 0;
}