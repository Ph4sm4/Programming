#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){

    fstream wejscie, wyjscie; //ifstream wejscie, ofstream wyjscie
    wejscie.open("tekst1_spolgloski.txt", ios::in);
    wyjscie.open("zaszyfrowane.txt", ios::out);

    cout<<"Podaj klucz dla samoglosek: ";
    int klucz_samo, klucz_spol;
    cin>>klucz_samo;
    cout<<"Podaj klucz dla spolglosek: ";
    cin>>klucz_spol;
    string wyraz;

    auto cezar = [](string tekst, int kl, int kl2)->string{
        const string alfabet = "a¥bc†de©fghijklˆmnäo¢pqrs˜tuvwxyz«¾";
        const char samogloski[] = {'a', '¥', 'e', '©', 'i', 'o', 'u', 'y'};
        for(int i = 0; i < tekst.length(); i++){
            bool found = false;
            for(int j = 0; j < 8; j++){
                if(tekst[i] == samogloski[j]){
                    found = true;
                    break;
                }
            }
            const short int index = alfabet.find(tekst[i]);
            if(!isblank(tekst[i])){
                if(found){
                    if(index + kl > alfabet.length()-1){
                        tekst[i] = alfabet[index + kl - 35];
                    }
                    else{
                        tekst[i] = alfabet[index + kl];
                    }
                }
                    else{
                        if(index + kl2 > alfabet.length()-1){
                            tekst[i] = alfabet[index + kl2 - 35];
                        }
                        else{
                            tekst[i] = alfabet[index + kl2];
                        }
                }
            }
            
        }
        return tekst;
    };
    while(getline(wejscie, wyraz)){
        transform(wyraz.begin(), wyraz.end(), wyraz.begin(), ::tolower);
        wyjscie<<cezar(wyraz, klucz_samo, klucz_spol)<<endl;
    }
    
    wyjscie.close();
    wejscie.close();

    return 0;
}