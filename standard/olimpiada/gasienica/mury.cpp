#include <bits/stdc++.h>
using namespace std;
//50pkt

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin>>n>>h;
    vector<int> dol;
    vector<int> gora;
    dol.resize(h+1);
    gora.resize(h+1);
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) cin>>dol[i];
        else cin>>gora[i];
    }

    vector<int> sum1; //dla dolu
    vector<int> sum2; //dla gory
    sum1.resize(h+1);
    sum2.resize(h+1);
    sum1[0] = 0;
    sum2[0] = 0;
    for(int i = 1; i <= h; i++){
        sum1[i] = count(dol.begin(), dol.end(), i);
        if(h - gora[i] + 1 >= 0) sum2[h - gora[i] + 1]++;
    }
    
    vector<int> suff;
    vector<int> pref;
    suff.resize(h+1);
    pref.resize(h+1);

    int suma = 0;
    for(int i = suff.size()-1; i >= 0; i--){
       suma += sum1[i];
       suff[i] = suma;
    }
    suma = 0;
    for(int i = 0; i < pref.size(); i++){
        suma += sum2[i];
        pref[i] = suma; 
    }

    vector<int> all;
    all.resize(pref.size());
    for(int i = 1; i < all.size(); i++){
        all[i] = pref[i] + suff[i];
    }
    
    int m = 99999999;
    for(int i = 1; i < all.size(); i++){
        if(m > all[i]) m = all[i];
    }
    cout<<m<<" "<<count(all.begin(), all.end(), m);

    return 0;
}