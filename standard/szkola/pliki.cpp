#include <iostream>
#include <fstream>
using namespace std;

int main(){

    string tekst;
    fstream plik;
    fstream plik2;
    plik2.open("wyniki.txt", ios::out);
    plik.open("data.txt", ios::in);
    int nr_linii = 1;
    while(getline(plik, tekst)){
        string substr = tekst.substr(0, tekst.find(" "));
        string substr2 = tekst.substr(tekst.find(" "), tekst.length());

        int first = stoi(substr), sec = stoi(substr2);
        int wynik = first*sec;

        if(wynik >= 250 && wynik <= 3000){
            plik2<<"Iloczyn liczb z linii: "<<nr_linii<<" - "<<first*sec<<endl;
        }
        nr_linii++;
    }

    plik.close();
    plik2.close();
    return 0;
}