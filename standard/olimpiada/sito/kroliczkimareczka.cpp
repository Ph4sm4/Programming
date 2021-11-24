#include <bits/stdc++.h>
using namespace std;

int tab[1000010];
//100
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j+=i){
            tab[j]++;
        }
    }
    for(int i = 0; i < k; i++) cout<<tab[i]<<" ";

    return 0;
}