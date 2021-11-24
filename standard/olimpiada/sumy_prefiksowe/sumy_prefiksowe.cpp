#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Podaj wielkosc tablicy: ";
    int n, sum = 0, x;
    cin>>n;
    int *tab = new int [n];
    for(int i = 0; i < n; i++) {
        cin>>x;
        sum += x;
        tab[i] = sum;
    }
    for(int i = 0; i < n; i++) cout<<tab[i]<<" ";
    cout<<"\nPodaj przedzial z jakiego chcesz otrzymac sume: ";
    int lewy, prawy;
    cin>>lewy>>prawy;

    tab[prawy-1] -= tab[lewy-2]; //-1 oraz -2 poniewaz podajemy przedzialy nie od 0 a od 1
    
    cout<<"\nSuma z przedzialu "<<lewy<<"-"<<prawy<<": "<<tab[prawy-1]<<endl;

    return 0;
}