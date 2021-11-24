#include <bits/stdc++.h>
using namespace std;

int main(){

    stack<int> s;
    int a;
    while(a != 0){
        cin>>a;
        s.push(a);
    }
    cout<<s.size();

    return 0;
}