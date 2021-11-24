#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream wejscie;
    wejscie.open("dane2_4.txt");

    string wyraz;
    while(getline(wejscie, wyraz)){
        int otw = 0, zamkn = 0;
        for(int i = 0; i < wyraz.length(); i++){
            if(wyraz[i] == '[') otw++;
            else if(wyraz[i] == ']') zamkn++;
        }
        if(otw == zamkn) cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
    }

    wejscie.close();

    return 0;
}