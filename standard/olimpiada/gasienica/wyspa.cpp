#include <bits/stdc++.h>
using namespace std;
//40pkt
int main(){
    
    int n;
    cin>>n;
    vector<int> v;
    v.resize(n);
    int maxsuma = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        maxsuma += v[i];
    }
    int najw = maxsuma/2;
    int lewy = 0, prawy = 0, suma = 0;
    pair<int, int> maxp = {0,0};
    while(lewy < n && prawy < n){
        if(suma < najw){
            suma += v.at(prawy);
            prawy++;
        }
        else{
            if(suma == najw){
                maxp = max(maxp, make_pair(suma, maxsuma-suma));
            }
            suma -= v.at(lewy);
            lewy++;
        }

    }
    cout<<min(maxp.first, maxp.second);
    //40 pkt :/

    return 0;
}