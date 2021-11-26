#include <bits/stdc++.h>
using namespace std;

template<typename T>
bool contains(vector<T> &a, T b){
    for(auto it = a.begin(); it != a.end(); it++){
        if(*it == b) return true;
    }
    return false;
}
template<typename T>
bool is_good(vector<T> &a, vector<T> &b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main(){

    int n, l;
    cin>>n>>l;
    vector<int> ile; 
    vector<int> co;
    map<int, int> mapa; //jaka liczba, ile jej jest
    ile.resize(l);
    co.resize(l);
    int howManyNum = 0;
    for(int i = 0; i < l; i++){
        cin>>ile[i];
        howManyNum += ile[i];
    }
    for(int i = 0; i < l; i++){
        cin>>co[i];
        mapa.insert(make_pair(co[i], 0));
    }
    vector<int> liczby;
    liczby.resize(n);
    for(int i = 0; i < n; i++){
        cin>>liczby[i];
    }
    int ct = 0, prawy = 0, lewy = 0, dl = 0;
    while(lewy < n && prawy < n){
        if(dl < l){
            dl++;
            prawy++;
        }
        else{
            dl--;
            lewy++;
        }
    }
    cout<<ct;


    return 0;
}