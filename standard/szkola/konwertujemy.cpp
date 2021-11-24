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

    int tab[1000], i = 0;
    do{
        tab[i] = liczba%system;
        liczba /= system;
        i++;
    }while(liczba);
    
    for(int j = i - 1; j>=0; j--){
        if(system>10){
                bool is_true = false;
                for(int z = 10; z <= system; z++){
                    if(tab[j] == z){
                    char x = 55+z;
                    cout<<x;
                    is_true = true;
                    break;
                    }  
                }
                if(!is_true){
                    cout<<tab[j];
                }
            
        }
        else{
            cout<<tab[j];
        }
        
    }
    
    return 0;
}