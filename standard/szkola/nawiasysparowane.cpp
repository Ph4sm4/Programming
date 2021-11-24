#include <bits/stdc++.h>
using namespace std;

void nie(){
    cout<<"NIE";
    exit(0);
}

int main(){

    string n;
    cin>>n;
    //int ct = 0;
    stack<int> s;
    // for(int i = 0; i < n.length(); i++){
    //     if(n[i] == '(') ct++;
    //     else ct--;
    // }
    if(n[0] == ')') nie();
    for(int i = 0; i < n.length(); i++){
        if(n[i] == '(') s.push(n[i]);
        else if(n[i] == ')' && !s.empty()) s.pop();
        else nie();
    }
    cout<<(s.empty()? "TAK" : "NIE");
    //if(!ct) cout<<"TAK";
    //else cout<<"NIE";

    return 0;
}