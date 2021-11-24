#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> tab[1000010];
bool vis[1000010];
vector<int> fish = {0};
//weszlo 100
void DFS(int a, ll &mx, ll &curr){
    vis[a] = true;
    curr += fish[a];
    for(int sasiad : tab[a]){
        if(!vis[sasiad]){
            DFS(sasiad, mx, curr);
        }
    }
    if(mx < curr) mx = curr;
    curr -= fish[a];
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, a, b;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        fish.push_back(x);
    }
    for(int i = 0; i < n-1; i++){
        cin>>a>>b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    ll mx = 0, curr = 0;

    DFS(1, mx, curr);

    cout<<mx;

    return 0;
}