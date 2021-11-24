#include <bits/stdc++.h>
using namespace std;

vector<int> tab[30010];
bool vis[30010];
//weszlo 100
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
    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
        int a;
        cin>>a;
        tab[a].push_back(i);
        tab[i].push_back(a);
    }
    int ct = 0;

    for(int i = 1; i <= n; i++){
        if(!vis[i]) {
            DFS(i);
            ct++;
        }
    }
    cout<<ct;

    return 0;
}