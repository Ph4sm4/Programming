#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
int tab[N];

//100
int up(int x, int n){
    int l = 0, p = n - 1, s;
    while(l < p){
        s = (l + p + 1)/2;
        if(tab[s] < x){
            l = s;
        } else p = s - 1;
    }
    if(tab[0] < x) l++;
    return l;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;

    cin>>tab[0];
    for(int i = 1; i < n; i++){
        int temp;
        cin>>temp;
        tab[i] = max(tab[i - 1], temp);
    }
    
    for(int i = 0; i < m; i++){
        int temp;
        cin>>temp;
        cout<<up(temp, n)<<' ';
    }
    


    return 0;
}