#include <bits/stdc++.h>
using namespace std;

vector<int> tab[1000010];
bool vis[1000010];
//weszlo 100
void DFS(int a, int started, bool &cycle, int last){
    if(cycle) return;
    vis[a] = true;
    
    for(int sasiad : tab[a]){
        if(!vis[sasiad]){
            DFS(sasiad, started, cycle, a);
        }else{
            if(sasiad == started && sasiad != last){
                cycle = true;
                return;
            }
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
    bool have_cycle = false;
    bool isConnected = true;

    if(n > m){
        DFS(1, 1, have_cycle, 1);
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                isConnected = false;
                break;
            }
        }
        cout<<(have_cycle || !isConnected? "NIE" : "TAK");
    }else cout<<"NIE";
    


    return 0;
}