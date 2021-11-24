#include <bits/stdc++.h>
using namespace std;

int main(){

    string n;
    cin>>n;
    int ct = 0;
    for(int i = 0; i < n.length(); i++){
        if(n[i] == '(') ct++;
        else ct--;
    }
    if(!ct) cout<<"TAK";
    else cout<<"NIE";

    return 0;
}