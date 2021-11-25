#include <bits/stdc++.h>
using namespace std;

vector<int> tab[1000010];
//100
int lb(int a, int val){
    if(tab[a].size() == 0) return -1;
    int l = 0, p = tab[a].size()-1, s;
    while(l < p){
        s = (l + p)/2;
        if(tab[a][s] >= val){
            p = s;
        } else l = s + 1;
    }
    return (tab[a][l] == val? l : -1);
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m, a, b;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>a>>b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    for(int i = 0; i < 1000010; i++){
        sort(tab[i].begin(), tab[i].end());
    }
    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>a>>b;
        if(lb(a, b) != -1) cout<<"TAK\n";
        else cout<<"NIE\n";
    }

    return 0;
}