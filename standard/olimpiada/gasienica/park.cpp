#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int *tab = new int [n];
    for(int i = 0; i < n; i++) cin>>tab[i];

    
    for(int i = 0; i < n; i++){
        int max_left = 0, max_right = 0;
        for(int j = 0; j <= i; j++) if(tab[j] > max_left) max_left = tab[j];
        for(int j = n-1; j >= i; j--) if(tab[j] > max_right) max_right = tab[j];
        cout<<max_left<<' '<<max_right<<'\n';
    }

    delete [] tab;

    return 0;
}