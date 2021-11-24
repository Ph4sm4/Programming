#include <iostream>
#include <cmath>
using namespace std;

int main(){

    cout<<"Podaj liczbe zestawow: ";
    int zestawy;
    cin>>zestawy;
    string *tab;
    tab = new string [zestawy];
    for(int i = 0; i < zestawy; i++){
        cin>>tab[i];
    }
    for(int i = 0; i < zestawy; i++){
        for(int j = 0; j < floor(tab[i].length()/2); j++){
            cout<<tab[i][j];
        }
        cout<<endl;
    }

    delete [] tab;

    return 0;
}