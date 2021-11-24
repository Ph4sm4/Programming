#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    cout<<"Podaj wyraz do zaszyfrowania: ";
    string wyraz;
    getline(cin, wyraz);
    cout<<"Podaj klucz [od -26 do 26]: ";
    int klucz;

    cin>>klucz;
    if(klucz > 26 || klucz < -26){
        cout<<"Niepoprawny klucz!"<<endl;
        exit(0);
    }
    
    for(int i = 0; i < wyraz.length(); i++){
        char c = wyraz[i];
        if(c <= char(90) && c >= 65 || c <= char(122) && c >= char(97)){
            if(klucz > 0){
                if(char(c) + klucz > char(90) && isupper(c) || char(c) + klucz > char(122)){
                    wyraz[i] = char(wyraz[i] - 26 + klucz);
                }
                else{
                    wyraz[i] = char(wyraz[i]) + klucz;
                }
            }
            else{
                if(char(c) + klucz < char(65) || char(c) + klucz < char(97) && islower(c)){
                    wyraz[i] = char(wyraz[i] + 26 + klucz);
                }
                else{
                    wyraz[i] = char(wyraz[i]) + klucz;
                }
            }
        }
    }
   
    cout<<"Zaszyfrowany wyraz: "<<wyraz<<endl;

    return 0;
}