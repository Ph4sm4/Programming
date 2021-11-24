#include <bits/stdc++.h>
using namespace std;

int main(){
    //100
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;

    vector<int> v(n);
    vector<int> pref(n + 1);
    pref[0] = 0;
    int suma = 0;
    vector<pair<int, int>> p(q);
    for(int i = 0; i < n; i++){
        cin>>v[i];
        suma += v[i];
        pref[i + 1] = suma;
    }
    for(int i = 0; i < q; i++) cin>>p[i].first>>p[i].second;
    for_each(p.begin(), p.end(), [pref](pair<int, int> temp){cout<<pref[temp.second] - pref[temp.first - 1]<<'\n';});

    return 0;
}