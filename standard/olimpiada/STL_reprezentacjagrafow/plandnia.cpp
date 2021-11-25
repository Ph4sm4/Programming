#include <bits/stdc++.h>
using namespace std;

//100
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<pair<int, int>> temp;
    for(int i = 0; i < n; i++){
        int m;
        cin>>m;
        for(int j = 0; j < m; j++){
            int a, b;
            cin>>a>>b;
            temp.push_back(make_pair(a,b));
        }
        sort(temp.begin(), temp.end(), [](pair<int, int> p1, pair<int, int> p2){
            if(p1.first < p2.first) return true;
            else if(p1.first > p2.first) return false;
            return p1.second <= p2.second;
        });
        bool good = true;
        for(int j = 0; j < m - 1; j++){
            if(temp[j].first == temp[j+1].first || temp[j].second > temp[j+1].first){
                cout<<"NIE\n";
                good = false;
                break;
            }
        }
        if(good) cout<<"TAK\n";
        temp.clear();
    }
    
    

    return 0;
}