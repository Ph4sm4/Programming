#include <bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        int ct = 0;
        vector<pair<int,int>> v;
        for(int j = 0; j < x; j++){
            pair<int, int> temp;
            cin>>temp.first>>temp.second;
            v.push_back(temp);
        }
        
    }


    return 0;
}