#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll NWD(ll x, ll y){
    if(x%y == 0) return y;
    NWD(y, x%y);
}
//100
int main(){

    ll a, b;
    cin>>a>>b;
    cout<<(a*b)/NWD(a,b);
    
    return 0;
}