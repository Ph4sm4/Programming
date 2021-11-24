#include <iostream>
using namespace std;


int main(){

    cout<<"Podaj napis: ";
    string tekst;
    cin>>tekst;

    cout<<"Podaj klucz: ";
    int klucz;
    cin>>klucz;

    for(int i = 0; i < tekst.length(); i++){
        tekst[i] = toupper(tekst[i]);
        if(tekst[i] >= 'A' && tekst[i] <= 'Z'){
            if(klucz > 0){
                if(tekst[i] + klucz%26 > char(90)){
                    tekst[i] = char(tekst[i] + klucz%26 - 26);
                }
                else{
                    tekst[i] = char(tekst[i] + klucz%26);
                }
            }
            else{
                if(tekst[i] + klucz%26 < char(65)){
                    tekst[i] = char(tekst[i] + klucz%26 + 26);
                }
                else{
                    tekst[i] = char(tekst[i] + klucz%26);
                }
            }
        }
    }
    cout<<"Zaszyfrowany wyraz: "<<tekst<<endl;

    return 0;
}