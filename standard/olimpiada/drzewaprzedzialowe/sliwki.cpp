#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 17;
int tab[2*base]; //values
int tab2[2*base][5]; //how many are divisible

void update(int _ind, int _val){
    int ind = _ind - 1;
    tab[ind] += _val;
    _ind += base;
    for(int i = 0; i < 5; i++){
        tab2[_ind][i] = (tab[ind]%(i+1) == 0? 1 : 0);
    }
    
    _ind /= 2;
    while(_ind > 0){
        tab2[_ind][0] = tab2[2*_ind][0] + tab2[2*_ind + 1][0];
        tab2[_ind][1] = tab2[2*_ind][1] + tab2[2*_ind + 1][1];
        tab2[_ind][2] = tab2[2*_ind][2] + tab2[2*_ind + 1][2];
        tab2[_ind][3] = tab2[2*_ind][3] + tab2[2*_ind + 1][3];
        tab2[_ind][4] = tab2[2*_ind][4] + tab2[2*_ind + 1][4];
        _ind /= 2;
    }
}

int query(int _start, int _end, int _mod){
    _start += base;
    _end += base;
    if(_start == _end) return tab2[_start][_mod-1];

    int res = tab2[_start][_mod-1] + tab2[_end][_mod-1];

    while(_start/2 != _end/2){
        if(_start % 2 == 0) res += tab2[_start + 1][_mod-1];
        if(_end % 2 == 1) res += tab2[_end-1][_mod-1];
        _start /= 2;
        _end /= 2;
    }
    return res;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    for(int i = 0; i < q; i++){
        string x;
        cin>>x;
        if(x == "DODAJ"){
            int a, b;
            cin>>a>>b;
            update(a, b);
        }else{
            int a,b,c;
            cin>>a>>b>>c;
            cout<<query(a,b,c)<<'\n';
        }
    }


    return 0;
}