#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream plik;
    plik.open("dane1_3.txt");
    int tab[1000];

    for(int i = 0; i < 1000; i++){
        plik>>tab[i];
    }
    int max = 0, max_temp = 0;
    for(int i = 0; i < 1000; i++){
        max_temp += tab[i];
        if(max_temp < 0) max_temp = 0;
        if(max < max_temp) max = max_temp;
    }
    cout<<max<<endl;

    plik.close();

    return 0;
}