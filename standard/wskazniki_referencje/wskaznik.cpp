#include <iostream>
using namespace std;

int hello(int *wskaznik){
    return ++(*wskaznik);
}
int referencja(int &ref){
    ref++;
}
void zwieksz_tablice(int *tab, int s){
    for(int i = 0; i < s; i++){
        tab[i]++;
    }
}

void zwieksz_tablice2(int *tab, int s){
    for(int i = 0; i < s; i++){
        tab[i] +=2;
    }
}

int main(){

    int i = 5;
    int z = 10;
    int *wks = &i;
    hello(wks);
    referencja(z);
    wks = &z;
    hello(wks);
    cout<<i<<endl;
    cout<<z<<endl;

    const int size = 10;
    int tab[size] = {0};
    zwieksz_tablice(tab, size);
    for(int i = 0; i < size; i++){
        cout<<tab[i]<<" ";
    }

    cout<<endl;

    const int size2 = 5;
    int tab2[size2] = {2,2,2,2,2};
    zwieksz_tablice2(tab2, size2);
    for(int i = 0; i < size2; i++){
        cout<<tab2[i]<<" ";
    }

    return 0;
}