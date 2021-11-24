#include <bits/stdc++.h>
using namespace std;

int prime[1000000];
bool tab[1000000];
//50 ale imo testy sa zwalone bo dla najwiekszych przechodzi
void sito(int n){
    for(int i=2; i<=n; i++)
		tab[i] = true;

    for(int i = 2; i <= sqrt(n); i++){
        if(tab[i]){
            for(int j = i * i; j <= n; j += i){
                tab[j] = false;
            }
        }
    }
    int k = 0;
    for(int i = 2; i <= n; i++)
        if(tab[i]) 
            prime[k++] = i;
}

void solve(int x){
    int i = 0;
    while(x > 1){
        if(x % prime[i] == 0){
            x /= prime[i];
            cout<<prime[i]<<" ";
        }else i++;
    }
    cout<<'\n';
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    sito(1000000);

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        solve(x);
    }


    return 0;
}