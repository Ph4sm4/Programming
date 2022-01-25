#include <bits/stdc++.h>
using namespace std;

int main(){

    queue<int> q;
    int x;
    int mx = -1 << 20;
    int curr = 0;
    
    while(cin>>x){
        if(!x) break;
        if(x == 1){
            curr++;
            q.push(1);
        }
        else {
            curr--;
            q.pop();
        }
        if(mx < curr) mx = curr;
    }
    cout<<mx;


    return 0;
}