#include <bits/stdc++.h>
using namespace std;

int silnia(int n){
    if(n == 0) return 1;
    return silnia(n-1) * n;
}
//100
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    cout<<silnia(n);

    return 0;
}