#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    
    ifstream plik;
    plik.open("labirynt.txt");
    string linia;

    getline(plik, linia);
    cout<<setw(5);
    for(int i = 0; i < linia.length(); i++){
        cout<<i<<setw(3);
    }
    cout<<'\n';
    int x = 0;
    while(getline(plik, linia)){
        cout<<x<<(x < 10? " " : "")<<setw(3);
        for(auto e : linia) cout<<(e == 'X'? 'X' : ' ')<<setw(3);
        x++;
        cout<<'\n';
    }
    plik.close();


    return 0;
}