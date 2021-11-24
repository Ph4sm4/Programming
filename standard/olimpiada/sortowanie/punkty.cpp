#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;
    int z;
};
//100
int main(){

    int n;
    cin>>n;
    vector<point> v;
    for(int i = 0; i < n; i++){
        point p;
        cin>>p.x>>p.y>>p.z;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), [](point p1, point p2){
        if(p1.x == p2.x && p1.y == p2.y) return p1.z < p2.z;
        else if(p1.x == p2.x) return p1.y < p2.y;
        return p1.x < p2.x;
    });
    for(auto el : v){
        cout<<el.x<<" "<<el.y<<" "<<el.z<<'\n';
    }

    return 0;
}