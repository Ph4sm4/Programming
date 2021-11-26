#include <bits/stdc++.h>
using namespace std;

vector<int> tab[5010];
bool vis[5010];
int dist[5010];
queue<int> q;
int inf = 1 << 30;
//zleeeeeeeee
void DFS(int a, int start, int &ct, bool &cycle){
    vis[a] = true;
    ct++;
    for(int sasiad : tab[a]){
        if(!vis[sasiad]){
            DFS(sasiad, start, ct, cycle);
        }else if(sasiad == start && a != start) {
            cycle = true;
        }
    }
}

void BFS(int a, int b, int &ct, bool &cycle){
    for(int i = 0; i < 5010; i++){
        vis[i] = false;
        dist[i] = inf;
    }
    dist[a] = 0;
    if(a == b){
        DFS(a, a, ct, cycle);
        return;
    }
    vis[a] = 0;
    q.push(a);
    while(!q.empty()){
        int z = q.front();
        q.pop();
        for(int sasiad : tab[z]){
            if(!vis[sasiad]){
                vis[sasiad] = true;
                dist[sasiad] = dist[z] + 1;
                q.push(sasiad);
            }
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k;
    cin>>n>>m>>k;
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    for(int i = 0; i < k; i++){
        int a, b, c;
        cin>>a>>b>>c;
        int ct = 0;
        bool cycle = false;
        BFS(a, b, ct, cycle);
        //cout<<ct<<endl;
        if(dist[b] == c || (cycle && c%ct == 0)) cout<<"TAK\n";
        else cout<<"NIE\n";
    }

    return 0;
}