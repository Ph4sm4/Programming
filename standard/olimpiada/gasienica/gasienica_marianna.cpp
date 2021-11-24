#include <bits/stdc++.h>
using namespace std;

int tab[1000010];
//100
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>tab[i];
    }
    int l = 0, r = 0;
    int ct = 0, len = 0;
    int mx = INT_MAX;
    while(l < n && r < n){
        if(ct < m){
            if(tab[r] == 1) ct++;
            len++;
            r++;
        }else{
            if(len - m < mx) mx = len - m;
            len--;
            if(tab[l] == 1) ct--;
            l++;
        }
    }
    if(mx == INT_MAX) cout<<"NIE";
    else cout<<mx;

    return 0;
}