#include <bits/stdc++.h>
using namespace std;

int NWD(int x, int y){
    if(x%y == 0) return y;
    return NWD(y, x%y);
}

int main(){

    cout<<"Podaj 2 liczby: ";
    int x,y;
    cin>>x>>y;

    cout<<"NWD: "<<NWD(x,y);

    return 0;
}