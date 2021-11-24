#include <bits/stdc++.h>
using namespace std;

vector<int> tab[1000010];
//56 przechodzi wszystkie testy ale na wiekszych obcina punkty
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m, a, b;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>a>>b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>a>>b;
        if(find(tab[a].begin(), tab[a].end(), b) != tab[a].end()) cout<<"TAK\n";
        else cout<<"NIE\n";
    }

    return 0;
}