#include <iostream>
using namespace std;

int main(){

    cout<<"Podaj system: ";
    int system;
    cin>>system;
    if(system == 1 || system == 0){
        cout<<"ERROR"<<endl;
        exit(0);
    }
    cout<<"Podaj liczbe: ";
    int liczba;
    cin>>liczba;

    int tab[31], i = 0;
    while(liczba){
        tab[i] = liczba%system;
        liczba /= system;
        i++;
    }

    for(int j = i - 1; j>=0; j--){
        if(system>10){
                bool czy_literka_wypisana = false;
                for(int z = 10; z <= system; z++){
                    if(tab[j] == z){
                    char x = 55+z;
                    cout<<x;
                    czy_literka_wypisana = true;
                    break;
                    }  
                }
                if(!czy_literka_wypisana){
                    cout<<tab[j];
                }
        }
        else{
            cout<<tab[j];
        }
        
    }
    
    return 0;
}
