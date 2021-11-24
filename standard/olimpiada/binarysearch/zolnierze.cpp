#include <bits/stdc++.h>
using namespace std;
#define ll long long

//100pkt
bool check(ll x, vector<int> v){
    ll suma = 0, indeks = 0, wiersz = 1;
    
    for(ll i = 0; i < x; i++){       
        if(suma + v[indeks] > x && wiersz == x || v[indeks] > x || x * x < v.size()) return false;
        else if(suma + v[indeks] > x && wiersz != x){
            i = 0;
            suma = 0;
            wiersz++;
        }
        suma += v[indeks];
        if(indeks == v.size() - 1) return true;
        indeks++;
    }
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int k;
    cin>>k;
    vector<int> v(k);
    for(int i = 0; i < k; i++){
        cin>>v[i];
    }
    ll l = 0, p = 10e9, s;
    while(l < p){
        s = (l + p)/2;
        if(check(s, v)){
            p = s;
        }else l = s + 1;
    }
    cout<<p;

    return 0;
}