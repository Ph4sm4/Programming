#include <bits/stdc++.h>
using namespace std;

struct bact{
    int masa;
    int iq;
};
struct lid{
    int val;
    int masa;
    int maxiq;
    int miniq;
};

lid lider[1000010];
bact tab[1000010];

int FIND(int x){
    if(lider[x].val == x) return x;
    lider[x].val = FIND(lider[x].val);
    return lider[x].val;
}

void UNION(int x, int y){
    lider[FIND(x)].miniq = min(lider[FIND(x)].miniq, lider[FIND(y)].miniq);
    lider[FIND(x)].maxiq = max(lider[FIND(x)].maxiq, lider[FIND(y)].maxiq);
    lider[FIND(x)].masa += lider[FIND(y)].masa;
    lider[FIND(y)].val = FIND(x);
}


int INF = 1 << 20;

int main(){
    //100
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= 1000010; i++){
        lider[i].val = i;
        lider[i].miniq = INF;
    }
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>tab[i].masa>>tab[i].iq;
        lider[i].maxiq = tab[i].iq;
        lider[i].miniq = tab[i].iq;
        lider[i].masa = tab[i].masa;
    }
    string x;
    int a, b;
    while(cin>>x){
        if(x == "JOIN"){
            cin>>a>>b;
            if(FIND(a) != FIND(b))
                UNION(a,b);
        }
        else if(x == "IQ_MIN"){
            cin>>a;
            
            cout<<lider[FIND(a)].miniq<<'\n';
        }
        else if(x == "IQ_MAX"){
            cin>>a;
            cout<<lider[FIND(a)].maxiq<<'\n';
        }
        else{
            cin>>a;
            cout<<lider[FIND(a)].masa<<'\n';
        }

    }


    return 0;
}