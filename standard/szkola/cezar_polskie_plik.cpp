#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string cezar(string n, int k){

    const string alfabet_duze = "A•BC∆DE FGHIJKL£MN—O”PQRSåTUVWXYZèØ";
    const string alfabet_male = "aπbcÊdeÍfghijkl≥mnÒoÛpqrsútuvwxyzüø";

    for(int i = 0; i < n.length(); i++){
        bool contains = false;
        for(int j = 0; j < alfabet_male.length(); j++){
            if(n[i] == alfabet_male[j] || n[i] == alfabet_duze[j]){
                contains = true;
                break;
            }
            if(j == alfabet_male.length() - 1 && !contains) break;
        }
        
        if(!isblank(n[i]) && contains){
            if(islower(n[i]) || n[i] == 'π' || n[i] == 'Ê' || n[i] == 'Í' || n[i] == '≥' || n[i] == 'Ò' || n[i] == 'Û' || n[i] == 'ú' || n[i] == 'ü' || n[i] == 'ø'){
                auto index = alfabet_male.find(n[i]);
                if(int(index) + k > alfabet_male.length()-1){
                    n[i] = alfabet_male[int(index) + k - 35];
                }
                else{
                    n[i] = alfabet_male[index + k];
                }
            }
            else{
                auto index = alfabet_duze.find(n[i]);
                if(int(index) + k > alfabet_duze.length()-1){
                    n[i] = alfabet_duze[int(index) + k - 35];
                }
                else{
                    n[i] = alfabet_duze[index + k]; 
                }     
            }   
        }
    }
    return n;
}

int main(){

    ifstream wejscie;
    ofstream wyjscie;
    wejscie.open("tekst_jawny_2.txt");
    wyjscie.open("szyfrogram2.txt");
    string wyraz;
    cout<<"Podaj klucz: ";
    int klucz;
    cin>>klucz;

    while(getline(wejscie, wyraz)){
        wyjscie<<cezar(wyraz, klucz)<<endl;
    }


    wejscie.close();
    wyjscie.close();

    return 0;
}