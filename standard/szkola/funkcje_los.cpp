#include <iostream>
#include <cstdlib>
using namespace std;

int losuj(int liczba){
    return rand()%liczba;
}

int main(){

    cout<<"Podaj liczbe: ";
    int l1;
    cin>>l1;

    cout<<losuj(l1+1)<<endl;

    return 0;
}