#include <bits/stdc++.h>
using namespace std;

void check(string w, string w2, string &ans){
    for(int i = 0; i < w.length(); i++){
        if(w2.find(w[i]) != string::npos) {
            ans += w[i];
            w2.erase(w2.find(w[i]), 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b, ans = "", ans2 = "";
    cin>>a;
    cin>>b;
    check(a, b, ans);
    check(b, a, ans2);
    if(!ans.length()) cout<<"BRAK";
    else{
        cout<<ans.length()<<'\n'<<ans<<'\n';
        cout<<ans2.length()<<'\n'<<ans2;
    }

    return 0;
}