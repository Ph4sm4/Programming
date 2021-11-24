#include <iostream>
#include <iterator>
using namespace std;

int main(){

    cout<<"Podaj klucz: ";
    string klucz;
    cin>>klucz;
    cout<<"Podaj wyraz do zaszyfrowania: ";
    string wyraz;
    cin>>wyraz;

    string::iterator it = klucz.begin();

    for(int i = 0; i < wyraz.length(); i++){
        if(wyraz[i] >= 'A' && wyraz[i] <= 'Z'){
            if(it == klucz.end()) it = klucz.begin();

            if(char(*it) + (wyraz[i] - 65) > 90){
                wyraz[i] = char(*it) + (wyraz[i] - 65) - 26;
            }
            else{
                wyraz[i] = char(*it) + (wyraz[i] - 65);
            }
            ++it;
        }
    }
    
    cout<<"Zaszyfrowany wyraz: "<<wyraz<<endl;

    return 0;
}