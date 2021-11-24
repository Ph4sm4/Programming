#include <bits/stdc++.h>
using namespace std;
//100
int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    copy(v.rbegin(), v.rend(), ostream_iterator<int>(cout, " "));

    return 0;
}