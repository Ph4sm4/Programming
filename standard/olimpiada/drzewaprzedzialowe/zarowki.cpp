#include <bits/stdc++.h>
using namespace std;

bool state[1000010];
//20 do poprawy, jednak drzewo przedzialowe trzeba wykorzystac xd
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    string x;
    cin>>x;
    for(int i = 1; i <= x.length(); i++){
        if(x[i-1] == 'x'){
            state[i] = false;
        }else state[i] = true;
    }
    for(int i = 0; i < q; i++){
        char z;
        cin>>z;
        if(z == 'Q'){
            int x;
            cin>>x;
            cout<<(state[x]? "ON\n" : "OFF\n");
        }else{
            int a, b;
            cin>>a>>b;
            for(int j = a; j <= b; j++) state[j] = state[j]^1;
        }
    }


    return 0;
}