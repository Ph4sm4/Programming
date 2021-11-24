#include <bits/stdc++.h>
using namespace std;

vector<int> tab[1000010];
bool vis[1000010];

void DFS(int a){
    vis[a] = true;
    for(int sasiad : tab[a]){
        if(!vis[sasiad]){
            DFS(sasiad);
        }
    }
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
    DFS(1);
    for(int i = 1; i <= n; i++){
        if(vis[i]) cout<<"TAK\n";
        else cout<<"NIE\n";
    }

    return 0;
}