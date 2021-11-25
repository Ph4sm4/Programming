#include <bits/stdc++.h>
using namespace std;

pair<int, int> myMin(pair<int, int> p1, pair<int, int> p2){
    if(p1.first + p1.second >= p2.first + p2.second) return p2;
    return p1;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n); 
    for(int i = 0; i < n; i++) cin>>v[i];
    pair<int, int> p = {v[0], v[1]};
    for(int i = 2; i < n - 1; i+=2){
        p = myMin(p, make_pair(v[i], v[i+1]));
    }
    p = myMin(p, make_pair(*(--v.end()), v[0]));
    cout<<p.first<<" "<<p.second;

    return 0;
}