#include <iostream>
#include <cstdlib>
using namespace std;

void naszesnastkowy();
int i = 0, tab[100];

int main(){
    naszesnastkowy();


return 0;
}

void naszesnastkowy(){
    system("cls");
    int liczba;

    cout<<"Podaj liczbe: ";
    cin>>liczba;
    cout<<"Liczba po przeliczeniu: ";
    do{
        tab[i++] = liczba%16;
        liczba = liczba/16;
    }while(liczba);

    for(int j = i - 1; j>=0; j--){
        switch(tab[j]){
            case 10: cout<<"A"; break;
            case 11: cout<<"B"; break;
            case 12: cout<<"C"; break;
            case 13: cout<<"D"; break;
            case 14: cout<<"E"; break;
            case 15: cout<<"F"; break;
        }
        if(tab[j] < 10){
            cout<<tab[j];
        }

    }
        exit(0);
}
