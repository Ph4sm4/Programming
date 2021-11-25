#include <bits/stdc++.h>
using namespace std;

//100
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    map<string, int> m;
    for(int i = 0; i < n; i++){
        string p;
        int temp;
        cin>>p>>temp;
        m.insert(make_pair(p, 0));
        m[p] += temp;
        if(m[p] < 0){
            cout<<"NIE\n";
            m[p] -= temp;
        }else cout<<m[p]<<'\n';
    }


    return 0;
}