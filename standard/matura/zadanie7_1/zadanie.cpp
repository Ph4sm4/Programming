#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){

    int tab[26] = {0};
    string wyraz;
    ifstream plik;
    plik.open("szyfrogram.txt");
    
    while(getline(plik, wyraz)){
        int index = 0;
        for(int i = 65; i <= 90; i++){
            tab[index] += count(wyraz.begin(), wyraz.end(), char(i));
            index++;
        }
    }
    for(int z = 65; int i : tab){
        cout<<char(z)<<" "<<i<<endl;
        z++;
    }
    plik.close();

    return 0;
}