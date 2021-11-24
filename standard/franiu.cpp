#include <iostream>
using namespace std;

int main(){

    int tab[5]; //deklaracja tablicy 5 elementowej, indeksy od 0 - 4
    //int - liczb calkowitych
    //char typ znakowy: a, b, c, d
    //string typ tekstowy: dasdasdas, dasdasdas
    //float typ zmiennoprzecinkowy: 1.23, 123.643

    int tab2[8] = {1,2,3,4,5,6,7,8}; //inicjalizacja tablicy 1 sposob
    int tab3[] = {1,2,3,4,5,6,7,8}; //inicjalizacja tablicy 2 sposob, kompilator sam zlicza

    string tab4[4];
    tab4[3] = "dalach";//mozna
    tab4[4] = "dfkj"; //tak nie mozna bo tablica ma 4 elemnty, indeksujemy od 0 - 3, wiec 4 indeks nie istnieje

    string imie = tab4[3]; //deklaracja z inicjalizacja
    string imie;//deklaracja
    imie = tab4[3];//przypisanie wartosci

    return 0;
}