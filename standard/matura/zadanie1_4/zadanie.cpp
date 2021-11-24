#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream plik;
    plik.open("dane1_4.txt");
    const int wiel = 100000;

    int tab[wiel];

    for(int i = 0; i <= wiel; i++){
        plik>>tab[i];
    }
    int max = 0, max_temp = 0, first = 0, end, new_first;
    for(int i = 0; i < wiel; i++){
        max_temp += tab[i];
        if(max_temp < 0){
            max_temp = 0;
            first = i;
        }
        if(max < max_temp){
            max = max_temp;
            new_first = first;
            end = i;
        }
    }
    cout<<new_first + 1<<" "<<end + 1<<endl;
    //ciekawe bo odpowiedz dla konca jest ok a poczatek ja o 1 za maly


    plik.close();

    return 0;
}