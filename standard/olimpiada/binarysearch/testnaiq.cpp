#include <bits/stdc++.h>
using namespace std;

const int N = 10e6;
vector<int> v[8];

int lb(int x, int pos){
    if(pos > v[x-1].size()) return -1;
    int l = 0, p = v[x-1].size(), s;
    while(l < p){
        s = (l + p)/2;
        if(v[x-1][s] < pos){
            p = s;
        }else{
            l = s + 1;
        }
    }
    cout<<l<<" | "<<pos<<" || ";
    return l > pos? 1 : -1;
}

int main(){

    //20 pkt, przekroczenie limitu czasu w reszcie
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int m;
    cin>>m;
    
    for(int i = 0; i < m; i++){
        int temp;
        cin>>temp;
        v[temp - 1].push_back(i + 1);
    }

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        vector<int> t(temp);
        for(int j = 0; j < temp; j++) cin>>t[j];
        bool found = true;
        for(int j = 0; j < temp; j++){
            if(lb(t[j], j) == -1){
                cout<<"NIE\n";
                found = false;
                break;
            }
        }
        if(found) cout<<"TAK\n";
    }


    return 0;
}