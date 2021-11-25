#include <bits/stdc++.h>
using namespace std;
//100
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    queue<string> q;

    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        string com;
        cin>>com;
        if(com == "nowy"){
            string name;
            cin>>name;
            q.push(name);
        }
        else if(com == "zawolaj"){
            cout<<q.front()<<'\n';
            q.pop();
        }
        else{
            cout<<q.size()<<'\n';
        }
    }
    



    return 0;
}