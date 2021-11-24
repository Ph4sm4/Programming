#include <bits/stdc++.h>
using namespace std;

struct oper{
    int first, second;
    char x;
};
//100
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    for(int i = 0; i < m; i++){
        oper o;
        cin>>o.first>>o.second>>o.x;
        if(o.x == 'M') sort(v.begin() + o.first - 1, v.begin() + o.second, greater<int>());
        else sort(v.begin() + o.first - 1, v.begin() + o.second);
    }
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    return 0;
}