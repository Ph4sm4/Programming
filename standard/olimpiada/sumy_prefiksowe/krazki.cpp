#include <bits/stdc++.h>
using namespace std;

//100;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, k;
    cin>>n>>k;
    vector<int> v;
    vector<int> krazki;
    vector<int> mi;

    v.resize(n+1);
    mi.resize(n+1);
    mi[0] = 0;
    v[0] = 0;
    krazki.resize(k);

    for(int i = 1; i < n+1; i++) cin>>v[i];

    for(int i = 0; i < k; i++) cin>>krazki[i];

    mi[1] = v[1];
    for(int i = 2; i < v.size(); i++) mi[i] = min(mi[i-1], v[i]);

    int z = 0;
    int h;
    for(int i = mi.size()-1; i > 0; i--){
        if(z == krazki.size()) break;
        if(krazki[z] <= mi[i]){
            h = i;
            z++;
        }
    }
    if(z == krazki.size()) cout<<h;
    else cout<<0;
    
}