#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int tab[500010];
int tab2[2][500010];
//weszlo 100
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int suma = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        tab[i] = 9 - temp;
        suma += temp;
    }
    for(ll i = 1; i <= n; i++){
        tab2[0][i] = tab2[1][i-1] + tab[i-1];
        tab2[1][i] = max(tab2[0][i-1], tab2[1][i-1]);
    }
    cout<<suma + max(tab2[0][n], tab2[1][n]);

    return 0;
}