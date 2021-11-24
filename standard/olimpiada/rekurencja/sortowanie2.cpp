#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &tab, int lewy, int prawy){
    if(prawy <= lewy) return;
    int pivot = tab[(lewy+prawy)/2];
    int i = lewy - 1, j = prawy + 1;
    while(true){
        while(pivot > tab[++i]); 
        while(pivot < tab[--j]); 
        if(i <= j) swap(tab[i], tab[j]); 
        else break;
    }
    if(i > lewy) quickSort(tab, lewy, j); 
    if(j < prawy) quickSort(tab, i, prawy);
}
//100
int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    quickSort(v, 0, n-1);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    return 0;
}