#include <bits/stdc++.h>
using namespace std;
//36 czas i pamiec bo n moze byc 2 000 000 wiec operacji by bylo 4 000 000 000 000 XD
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> v(n);
    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(v[i] % v[j] == 0) p.push_back(make_pair(i, j));
        }
    }
    cout<<p.size();


    return 0;
}