#include <bits/stdc++.h>
using namespace std;

bool check(double x, int n, vector<double> v){
    int rozstawione = 1, lastpos = v[0] + x;
    for(int i = 0; i < v.size(); i++){
        if(abs(v[i] - lastpos) > x){
            lastpos = v[i] + x;
            rozstawione++;
        }
        if(rozstawione == n && i != v.size() - 1) return false;
    }
    return true;
}

int main(){

    int k;
    cin>>k;
    vector<double> ans(k);
    for(int i = 0; i < k; i++){
        int n, m;
        cin>>n>>m;
        vector<double> temp(m);
        for(int j = 0; j < m; j++){
            cin>>temp[j];
        }
        int l = 0, p = 1e6, s, mx = 0;
        while(l < p){
            s = (l + p)/2;
            if(check(s, n, temp)){
                p = s;
            }else l = s + 1;
        }
        ans[i] = l;
    }
    for(auto e : ans) cout<<e<<endl;

    return 0;
}