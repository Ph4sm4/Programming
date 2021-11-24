#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <regex>
using namespace std;
int tab[26] = {0}, tab2[26] = {0};

void Calc(string str, regex reg){
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;

    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        string temp = match.str();
        
        for(int i = 65; i <= 90; i++){
            if(temp[0] == char(i)){
                tab[i - 65]++;
                break;
            }
        }
        for(int i = 97; i <= 122; i++){
            if(temp[0] == char(i)){
                tab2[i - 97]++;
                break;
            }
        }
        currentMatch++;
    }
    cout<<endl;
}

int main(){
    string wyraz;
    ifstream plik;
    plik.open("zlicz.txt");
    regex reg("([^\\s]+)");
    
    while(getline(plik, wyraz)){
        Calc(wyraz, reg);
    }
    
    for(int z = 65; int i : tab){
        cout<<char(z)<<" "<<i<<endl;
        z++;
    }
    for(int z = 97; int i : tab2){
        cout<<char(z)<<" "<<i<<endl;
        z++;
    }
    plik.close();

    return 0;
}