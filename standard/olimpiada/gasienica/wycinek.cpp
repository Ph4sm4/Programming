#include <bits/stdc++.h>
using namespace std;

int main(){
    //50pkt

    int n, wyc;
    cin>>n>>wyc;
    vector<int> v;
    vector<int> pref;
    v.resize(n);
    pref.resize(n);

    int suma = 0;

    vector<pair<int, int>> all;
    all.resize(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
        suma += v[i];
        pref[i] = suma;
        all[i].first = pref[i];
        all[i].second = i+1;
    }
    sort(all.begin(), all.end());
    int pocz = 0, kon = 0, m = -1, mx = -1;
    while(pocz < n && kon < n){
        if(all[kon].first - all[pocz].first <= wyc){
            kon++;
            if(all[kon].first - all[pocz].first == wyc){
                m = all[kon].second - all[pocz].second;
            }
        }
        else{
            pocz++;
        }
        if(mx < m) mx = m;
    }
    if(mx <= 0) cout<<"BRAK";
    else cout<<mx;

    return 0;
}