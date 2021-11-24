#include <bits/stdc++.h>
using namespace std;

vector<int> tab[500010];
bool vis[500010];
int pre[500010];
int post[500010];
int preind = 1, postind = 1;
//100
void DFS(int a){
    vis[a] = true;
    pre[a] = preind++;
    for(int sasiad : tab[a]){
        if(!vis[sasiad]){
            DFS(sasiad);
        }
    }
    post[a] = postind++;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i = 0; i < n - 1; i++){
        int a;
        cin>>a;
        tab[a].push_back(i + 1);
        tab[i + 1].push_back(a);
    }
    DFS(0);

    while(true){
        int a, b;
        cin>>a; 
        if(a == -1) break;
        cin>>b;
        if(pre[a] < pre[b] && post[a] > post[b]) cout<<"TAK\n";
        else cout<<"NIE\n";
    }


    return 0;
}