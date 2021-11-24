#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){//100
    cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);

    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i];
    }
    ll p = 0, x = 0, m = -999999999;
    while(p < n){
        if(x >= 0){
            x += v[p++];
            if(m < x) m = x;
        }
        else x = 0;
        
    }
    cout<<m;



    return 0;
}