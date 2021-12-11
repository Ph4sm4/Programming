#include <bits/stdc++.h>
using namespace std;

struct krwa{
    int id;
    int waga;
};

vector<kraw> v[100010];
int dist[100010];
const long long INF = LONG_LONG_MAX;
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int x){
    int id, d;
    for(int i = 0; i < 100010; i++){
        dist[i] = INF;
    }
    dist[x] = 0;
    q.push({0, x});

    while(!pq.empty()){
        d = pq.top().first;
        id = pq.top().second;
        q.pop();
        if(dist[id] < d) continue;
        
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;



    return 0;
}