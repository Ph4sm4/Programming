#include <bits/stdc++.h>
using namespace std;

void sito(bool *tab, int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(tab[i]){
            for(int j = i * i; j <= n; j += i){
                tab[j] = false;
            }
        }
    }
}
//100
bool tab[1000010];
int pref[1000010];
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int j = 2; j <= 1000010; j++){
        tab[j] = true;
    }
    sito(tab, 1000010);
    int ct = 0;
    for(int i = 0; i < 1000010; i++){
        if(tab[i]){
            ct++;
        }
        pref[i] = ct;
    }
    for(int i = 0; i < n; i++){
        int a, b;
        cin>>a>>b;
        cout<<pref[b] - pref[a-1]<<'\n';
    }

    return 0;
}