#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void losuj(int *tab, int size){
    for(int i = 0; i < size; i++){
        tab[i] = rand()%100;
    }
}

int main(){
    srand(time(NULL));
    int tab[10];
    losuj(tab, 10);
    for(int i : tab) cout<<i<<endl;
    cout<<"Podaj liczbe: ";
    int num;
    cin>>num;

    auto sprawdz = [](int *tab, int size, int &liczba)->bool{
        for(int i = 0; i < size; i++){
            if(liczba == tab[i]) return true;
        }
        return false;
    };
    cout<<boolalpha;
    cout<<sprawdz(tab, 10, num)<<endl;


    return 0;
}