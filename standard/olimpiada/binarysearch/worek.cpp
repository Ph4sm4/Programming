#include <bits/stdc++.h>
#define ll long long 
using namespace std;

vector<ll> v;

ll lb(ll x){
    ll l = 0, p = v.size()-1, s;
    while(l < p){
        s = (l + p)/2;
        if(v[s] >= x){
            p = s;
        } else l = s + 1;
    }
    return (v[l] == x? l : 0);
}

ll up(ll x){
    ll l = 0, p = v.size()-1, s;
    while(l < p){
        s = (l + p + 1)/2;
        if(v[s] <= x){
            l = s;
        } else p = s - 1;
    }
    return (v[l] == x? l + 1 : 0);
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;

    v.resize(n);
    for(ll i = 0; i < n; i++){
        cin>>v[i];
    }
    ll q;
    cin>>q;
    
    vector<ll> inp(q);
    for(ll i = 0; i < q; i++){
        cin>>inp[i];
    }
    sort(v.begin(), v.end());
    if(n == 0) for(int i = 0; i < q; i++) cout<<0<<'\n';
    else if(q == 0) cout<<0;
    else
        for(ll i = 0; i < q; i++)
            cout<<up(inp[i]) - lb(inp[i])<<'\n';

    
    return 0;
}