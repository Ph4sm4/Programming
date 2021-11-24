#include <bits/stdc++.h>
using namespace std;

void fib(int n){
    int a = 0, b = 1;
    for(int i = 0; i < n; i++){
        cout<<b<<" ";
        b += a;
        a = b - a;
    }
}

int main(){

    cout<<"Podaj liczbe cyfr: ";
    int n;
    cin>>n;

    fib(n);

    return 0;
}