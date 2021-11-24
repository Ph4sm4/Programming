#include <bits/stdc++.h>
using namespace std;

vector<int> tab[1000010];
bool vis[1000010];
int pre[1000010];
int post[1000010];
int preind = 1, postind = 1;

//weszlo 100

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

    int n, a;
    cin>>n;
    for(int i = 0; i < n - 1; i++){
        cin>>a;
        tab[i+1].push_back(a);
        tab[a].push_back(i+1);
    }
    DFS(0);

    int x, y;
    while(true){
        cin>>x; 
        if(x == -1) break;
        cin>>y;
        if((pre[x] < pre[y] && post[x] > post[y])) cout<<"TAK\n";
        else cout<<"NIE\n";
    }



    return 0;
}