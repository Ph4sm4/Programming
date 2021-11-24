#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin>>t;

    for(int i = 0; i < t; i++){
        int z;
        cin>>z;
        string tab[2];
        for(int j = 0; j < 2; j++){
            cin>>tab[j];
        }
        bool bad = false;
        for(int j = 0; j < z; j++){
            if(tab[0][j] == '1' && tab[1][j] == '1'){
                cout<<"NO\n";
                bad = true;
                break;
            }
        }
        if(!bad) cout<<"YES\n";
    }



    return 0;
}