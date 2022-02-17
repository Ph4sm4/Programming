#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k){

    return n == 1? 1 : (solve(n-1, k) + k - 1)%n + 1;
}

int main(){

    int n, k;
    cin>>n>>k;
    cout<<solve(n, k);

    return 0;
}