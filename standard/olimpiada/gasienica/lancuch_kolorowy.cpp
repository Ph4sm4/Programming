#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> input(m);
    vector<pair<int,int>> current;
    vector<int> v(n);
    int total = 0;

    for(int i = 0; i < m; i++) {
        cin>>input[i].second;
        total += input[i].second;
    } //amount
    for(int i = 0; i < m; i++) cin>>input[i].first; //what
    for(int i = 0; i < n; i++) cin>>v[i];

    copy(input.begin(), input.end(), back_inserter(current));
    for_each(current.begin(), current.end(), [](pair<int, int> &a){a.second = 0;});

    int ct = 0, good = 0;
    int l = 0, r = 0, dl = 0;
    while(l < n && r < n){
        if(good == total) ct++;
        if(dl <= m){
            if()
            dl++;
            r++;
        }
    }

    cout<<ct;

    return 0;
}