#include <bits/stdc++.h>
using namespace std;

vector<int> tab[1000010];
bool vis[1000010];
int dist[1000010];
queue<int> q;
const int inf = 1 << 30;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m, a, b;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    for(int i = 1; i < 1000010; i++){
        dist[i] = inf;
    }
    vis[1] = true;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        a = q.front();
        q.pop();
        for(int sasiad : tab[a]){
            if(!vis[sasiad]){
                vis[sasiad] = true;
                dist[sasiad] = dist[a] + 1;
                q.push(sasiad);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(dist[i] == inf){
            cout<<-1<<"\n";
        }else{
            cout<<dist[i]<<"\n";
        }
    }

    return 0;
}