#include <iostream>
using namespace std;

int main(){

    int ile;
    cin>>ile;
    int *tab;
    tab = new int [ile];
    for(int i = 0; i < ile; i++){
        int temp, silnia = 1;
        cin>>temp;

        for(int j = 1; j <= temp; j++){
            silnia *= j;
        }
        tab[i] = silnia;
    }
    for(int i = 0; i < ile; i++){
        cout<<tab[i]/10<<" "<<tab[i]%10<<endl;
    }
    

    delete [] tab;
    return 0;
}