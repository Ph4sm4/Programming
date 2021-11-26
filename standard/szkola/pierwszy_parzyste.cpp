#include <iostream>
using namespace std;

const int n = 10;
int sprawdz(int *tab){
    int low = 0, max = n-1, mid = (low+max)/2;
    while(low < max){
        mid = (low+max)/2;
        if(tab[mid]%2 != 0) low = mid+1;
        else max = mid;
    }
    if(tab[max]%2 == 0) return max;
    else return -1;
}

int main(){

    int tab[n];
    
    for(int i = 0; i < n; i++){
        cout<<"Podaj liczbe: ";
        cin>>tab[i];
    }
    cout<<sprawdz(tab)<<endl;

    return 0;
}