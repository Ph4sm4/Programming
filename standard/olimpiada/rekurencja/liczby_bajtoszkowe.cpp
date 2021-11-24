#include <bits/stdc++.h>
using namespace std;

int calc(int n){
    if(n == 1 || n == 2 || n == 3) return 1;
    return calc(n - 1) + calc(n - 3);
}
//100
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    cout<<calc(n);

    return 0;
}