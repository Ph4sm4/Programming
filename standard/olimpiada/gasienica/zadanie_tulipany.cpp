#include <bits/stdc++.h>
using namespace std;

int main(){

    set<int> tulipany;
    int ilosc;
    cin>>ilosc;
    for(int i = 0; i < ilosc; i++){
        int temp;
        cin>>temp;
        tulipany.insert(temp);
    }
    cout<<15000-tulipany.size()<<'\n';

    return 0;
}