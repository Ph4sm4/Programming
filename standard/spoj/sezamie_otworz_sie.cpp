#include <iostream>
#include <vector>
#include "printSTL.h"
#include <string>
using namespace std;

int main(){

    cout<<"Podaj liczbe zestawow danych: ";
    int zestawy;
    cin>>zestawy;

    vector<pair<string, string>> wpisz;

    string *tab;
    tab = new string [zestawy];

    for(int i = 0; i < zestawy; i++){
        string napis;
        pair<string, string> temp;
        cout<<"wpisz "<<i+1<<" zestaw: "<<endl;
        cin>>temp.first;
        cin>>temp.second;
        wpisz.push_back(temp);
        if(wpisz.at(i).first.length() != wpisz.at(i).second.length()){
            tab[i] = "NIE";
        }
        else{
            for(int j = 0; j < wpisz.at(i).first.length(); j++){
                if(wpisz.at(i).first != wpisz.at(i).second){
                    char temporary =  wpisz.at(i).second.front();
                    wpisz.at(i).second.erase(wpisz.at(i).second.begin());
                    wpisz.at(i).second.push_back(temporary);
                }
                else{
                    tab[i] = "TAK";
                    break;
                }
                if(j == wpisz.at(i).first.length()-1){
                    tab[i] = "NIE";
                }
            }
        }
    }

    for(int i = 0; i < zestawy; i++){
        cout<<tab[i]<<endl;
    }

    return 0;
}