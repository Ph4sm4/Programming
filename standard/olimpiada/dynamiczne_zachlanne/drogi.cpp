#include <bits/stdc++.h>
#define ll long long 
using namespace std;
    
ll tab[1010][1010];
ll tab2[1010][1010];
//weszlo na 100
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    for(int i = 0; i < 1010; i++){
        tab2[0][i] = 0;
        tab2[i][0] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>tab[i][j];
        }
    }
    tab2[0][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            tab2[i][j] = (tab[i-1][j-1] == 1? 0 : tab2[i-1][j] + tab2[i][j-1])%1000000;
        }
    }
    cout<<tab2[n][n];

    return 0;
}