#include <bits/stdc++.h>
using namespace std;

vector<int> tab[1000010];
queue<int> q;
int dist[1000010];
//20 czas
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin>>a>>b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    vector<int> v(k);
    for(int i = 0; i < k; i++) cin>>v[i];
    int max_dis = 0;
    for(auto el : v){
        bool vis[1000010];
        for(int i = 0; i < 1000010; i++) vis[i] = false;
        dist[el] = 0;
        vis[el] = true;
        q.push(el);
        while(!q.empty()){
            int a = q.front();
            q.pop();
            for(int sasiad : tab[a]){
                if(!vis[sasiad]){
                    vis[sasiad] = true;
                    dist[sasiad] = dist[a] + 1;
                    q.push(sasiad);
                }
            }
        }
        for_each(v.begin(), v.end(), [&max_dis](int a){if(dist[a] > max_dis) max_dis = dist[a];});
    }
    cout<<max_dis;
    

    return 0;
}