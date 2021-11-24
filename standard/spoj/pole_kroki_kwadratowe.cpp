#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int zestawy;
    cout<<"Podaj liczbe zestawow: ";
    cin>>zestawy;
    int *tab;
    tab = new int [zestawy];
    for(int i = 0; i < zestawy; i++){
        cout<<"Podaj "<<i+1<<" dana: ";
        cin>>tab[i];
    }
    for(int i = 0; i < zestawy; i++){
        auto oblicz = [tab, i](){cout<<pow(tab[i], 2)<<endl;};
        oblicz();
    }

    return 0;
}