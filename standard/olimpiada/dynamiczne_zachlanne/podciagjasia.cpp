#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll tab[2][1000010];
ll tab2[1000010];
//0 0 0 0 0 0 ...
//0 0 0 0 0 0 ...
//weszlo na 100
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin>>n;

    for(ll i = 0; i < n; i++) cin>>tab2[i];

    for(ll i = 1; i <= n; i++){
        tab[0][i] = tab[1][i-1] + tab2[i-1];
        tab[1][i] = max(tab[0][i-1], tab[1][i-1]);
    }
    cout<<max(tab[0][n], tab[1][n]);

    return 0;
}