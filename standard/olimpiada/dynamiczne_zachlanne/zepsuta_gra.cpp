#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll tab[1010][1010];
int main(){
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n + 1; i++) tab[0][i] = -999999999999;
    for(int i = 1; i <= m; i++) tab[i][0] = -999999999999;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>tab[i][j];
        }
    }
    int suma = 0;
    pair<int, int> curr = {1,1};
    for(int i = 0; i <= n + m - 2; i++){
        suma += tab[curr.first][curr.second];
        if(tab[curr.first + 1][curr.second] > tab[curr.first][curr.second + 1 ]) curr.first++;
        else curr.second++;
    }
    cout<<(suma < 0? 0 : suma);
    return 0;
}