#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout<<"Podaj n: ";
    int n;
    cin>>n;

    if(n<3){
        cout<<"Niemozliwe"<<endl;
        exit(0);
    }

    bool parzyste;

    if(n%2 == 0) parzyste = true;
    else parzyste = false;

    int *tab;
    tab = new int [n+1];

    for(int i = 0; i <= n; i++){
        tab[i] = i;
    }
    string suma;

    if(!parzyste){
        for(int i = 0; i < n; i++){
            int x = floor(n/2-i);
            if(i == floor(n/2)){
                suma += to_string(tab[x]);
                break;
            }
            suma += to_string(tab[x]) + " " + to_string(tab[(n-i)]) + " ";
            
        }
    }
    else{ 
        for(int i = 0; i < n; i++){
            int x = n/2-i;
            if(i == n/2){
                suma += to_string(tab[x]);
                break;
            }
            else{
               suma += to_string(tab[x]) + " " + to_string(tab[(n-i)]) + " ";       
            }
                  
        }
    }

    delete [] tab;

    cout<<suma<<endl;

    return 0;
}
