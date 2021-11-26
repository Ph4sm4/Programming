#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll tab[1010][1010];
ll tab2[1010][1010];
//100 weszlo
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin>>n>>m;

    for(int j = 0; j < 1010; j++){
        tab2[0][j] = -9999999999999;
        tab2[j][0] = -9999999999999;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>tab[i][j];
        }
    }
    tab2[0][1] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            tab2[i][j] = max(tab2[i-1][j], tab2[i][j-1]) + tab[i-1][j-1];
        }
    }
    cout<<tab2[n][m];


    return 0;
}