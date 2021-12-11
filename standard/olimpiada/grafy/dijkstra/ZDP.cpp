#include <bits/stdc++.h>
using namespace std;

struct kraw{
    int id;
    int waga;
};
//100
vector<kraw> v[500010];
long long dist[500010];
const long long inf = LONG_LONG_MAX;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int x){
    int id, d;
    for(int i = 0; i < 500010; i++){
        dist[i] = inf;
    }
    dist[x] = 0;
    pq.push({0, x});

    while(!pq.empty()){
        id = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if(dist[id] < d){
            continue;
        }
        for(auto kraw : v[id]){
            if(dist[id] + kraw.waga < dist[kraw.id]){
                dist[kraw.id] = dist[id] + kraw.waga;
                pq.push({dist[kraw.id], kraw.id});
            }
        }
    }

}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++){
        if(dist[i] == inf) cout<<"-1\n";
        else cout<<dist[i]<<'\n';
    }



    return 0;
}