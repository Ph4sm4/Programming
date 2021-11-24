#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int main(){

    int tab[26] = {0}, tab2[26] = {0};
    string wyraz;
    ifstream plik;
    ofstream wyjscie;
    plik.open("zlicz.txt");
    wyjscie.open("wyswietl_litery.txt");
    
    while(getline(plik, wyraz)){
        int index = 0;
        int index2 = 0;
        for(int i = 65; i <= 90; i++){
            tab[index] += count(wyraz.begin(), wyraz.end(), char(i));
            index++;
        }
        
        for(int i = 97; i <= 122; i++){
            tab2[index2] += count(wyraz.begin(), wyraz.end(), char(i));
            index2++;
        }
    }
    
    for(int z = 65; int i : tab){
        wyjscie<<char(z)<<" "<<i<<endl;
        z++;
    }
    for(int z = 97; int i : tab2){
        wyjscie<<char(z)<<" "<<i<<endl;
        z++;
    }
    plik.close();
    wyjscie.close();

    return 0;
}