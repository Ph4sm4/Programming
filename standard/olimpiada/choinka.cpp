#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if(n == 1) cout<<" ";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1 - i; j++) cout<<" ";
        for(int j = 0; j < 2 * i + 1; j++) cout<<"*";
        cout<<endl;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n - 2; j++) cout<<" ";
        for(int j = 0; j < 3; j++) cout<<"*";
        cout<<endl;
    }

    return 0;
}