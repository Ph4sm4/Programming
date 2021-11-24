#include <iostream>
using namespace std;

int main(){

    cout<<"Podaj liczbe zestawow: ";
    int zestawy;
    cin>>zestawy;
    string *tab;
    tab = new string [zestawy];

    for(int i = 0; i < zestawy; i++){
        cin>>tab[i];
        if(tab[i].length() != 11){
            cout<<"Niepoprawna dlugosc peselu!";
            exit(0);
        }
    }
    for(int i = 0; i < zestawy; i++){
        for(int j = 0; j < tab[i].length(); j++){
            int wynik = stoi(to_string(tab[i][j]))*1 + stoi(to_string(tab[i][j]))*3 + stoi(to_string(tab[i][j]))*7 + stoi(to_string(tab[i][j]))*9 +
            stoi(to_string(tab[i][j]))*1 + stoi(to_string(tab[i][j]))*3 + stoi(to_string(tab[i][j]))*7 + stoi(to_string(tab[i][j]))*9 +
            stoi(to_string(tab[i][j]))*1 + stoi(to_string(tab[i][j]))*3 + stoi(to_string(tab[i][j]))*1;
            if(to_string(wynik).back() == '0'){
                cout<<"Tak"<<endl;
                break;
            }else{
                cout<<"Nie"<<endl; 
                break;
            } 
        }
    }

    delete [] tab;

    return 0;
}