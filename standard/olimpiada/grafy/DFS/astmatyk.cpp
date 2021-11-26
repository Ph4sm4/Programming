#include <bits/stdc++.h>
using namespace std;

bool vis[1000000];
vector<int> g[1000000];
int dist[1000010];
queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;
    cin>>n>>m;
    vector<int> w(n);
    for(int i = 0; i < n; i++){
        cin>>a;
        w[i] = a;
    }
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //binary search w dfsie przechodzimy po wierzcholkach <= x a potem bin search po x

    return 0;
}